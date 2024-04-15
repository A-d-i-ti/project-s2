#include <iostream> 
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <tchar.h>
#include <thread>
#include <vector>                   // vector is used to store all the clients hitting the server 

using namespace std;

#pragma comment(lib,"ws2_32.lib")

bool Initialize() {
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void Interactwithclient(SOCKET clientSocket,vector<SOCKET>& clients) {
	// send/recieve 
	cout << "client connected " << endl;
	char buffer[4096];
	while (1) {             //to make it recive continues

		int bytesrecvd = recv(clientSocket, buffer, sizeof(buffer), 0);

		if (bytesrecvd <= 0) {                  // <=0 signifies that the client has disconnected 
			cout << "client disconnected " << endl;
			break;
		
		}

		string message(buffer, bytesrecvd);
		cout << "message from cleint : " << message << endl;
		for (auto clients : clients) {
			if (clients != clientSocket) {              // so that the one who is sending the message should not recieve back the same message 
				send(clients, message.c_str(), message.length(), 0);
			}
		
		}
	}

	auto it = find(clients.begin(), clients.end(), clientSocket);
	if (it != clients.end()) {
		clients.erase(it);
	
	}


}
int main() {
	if (!Initialize()) {
		cout << "winsock initialization failed " << endl;
		return 1;
	}

	cout << "sever program" << endl;
	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0); //inet bcs we using ipv4 mechanism,0-> default protocol provided by isp
	if (listenSocket == INVALID_SOCKET) {
		cout << " socket creation failed " << endl;
		return 1;

	}
	//create address structure 
	int port = 12345;
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	// convert the ip address (0.0.0.0) (the local host )put it inside sin_family in binary for
	if (InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1) {
		cout << "setting address structure failed " << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}
	// bind the ip with socket 
	if (bind(listenSocket, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR ){
		cout << " bind failed " << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}
	// listen 
	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
		cout << "listen failed " << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}
	cout << "server has started listening on port : " << port << endl;
	vector<SOCKET>clients;
	while (1) {
		// accept from client 
		SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
		if (clientSocket == INVALID_SOCKET) {
			cout << "invalid client socket " << endl;
		}
		clients.push_back(clientSocket);
		thread t1(Interactwithclient, clientSocket, std::ref(clients));
		t1.detach();
	}

	closesocket(listenSocket);

	WSACleanup();
	
	return 0; 

}
