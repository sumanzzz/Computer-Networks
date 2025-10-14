import socket # for socket 
import os

server_address = ('localhost',8888)

server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(server_address)

server_socket.listen(1)
print("Server is listening for incoming connections....")

while True:
	client_socket,client_address = server_socket.accept()
	print("Accepted connection from",client_address)
	
	file_name = client_socket.recv(1024).decode()
	print("Received file name:",file_name)
	
	if os.path.exists(file_name):

		with open(file_name,'rb') as file:
			file_contents = file.read()
			client_socket.send(file_contents)
	else:
		client_socket.send(b'File not found')
	client_socket.close()
		
