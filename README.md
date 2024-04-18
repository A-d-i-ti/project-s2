# project-sem-2 
a real time chat application in c++ with oops concepts + using socket programing '
- we have used the concept of socket programing and some APIs for the ease of the program.
- ![Screenshot (276)](https://github.com/A-d-i-ti/project-s2/assets/142913419/7cb23981-9537-473c-8e30-3aca189d7042)

### some common terms being used :
a.**SOCKET** :-A socket is a communications connection point (endpoint) that you can name and address in a network.
b.**Socket programming** shows how to use socket APIs to establish communication links between remote and local processes.
c.**vector** -vector class is a class template for sequence containers. A vector stores elements of a given type in a linear arrangement.
d.**thread** -Multithreading is a feature that allows concurrent execution of two or more parts of a program for maximum utilization of the CPU.



### libraries used :
1. < WINSOCK2.H > : Windows Sockets (Winsock) functions and service providers to place sockets into a set. The HOSTENT structure (winsock2. h) is used by functions to store information about a given host, such as host name, IPv4 address, and so forth.
### functions of winsock lib : 
1.htons (): The htons function takes a 16-bit number in host byte order and returns a 16-bit number in network byte order used in TCP/IP networks
2. InetPton() : The InetPton function converts an IPv4 or IPv6 Internet network address in its standard text presentation form into its numeric binary form.

### some APIs on socket  :
1. bind() : The bind() API call assigns the 'local' port number. That is, the port number that is used as the 'source port' on outgoing datagrams, and the 'destination port' on incoming datagrams.
2. listen () : int listen(int sockfd, int backlog); It puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection. The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow.
3. accept () : The accept() call creates a new socket descriptor with the same properties as socket and returns it to the caller.
4. send () :The send() function sends data on the socket with descriptor socket. The send() call applies to all connected sockets.
5. recieve () : The Receive method reads data into the buffer parameter and returns the number of bytes successfully read
