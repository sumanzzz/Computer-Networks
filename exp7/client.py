import socket

server_address = ('localhost',8888)

client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(server_address)

file_name = input("Enter the filename:")

client_socket.send(file_name.encode())

file_contents = client_socket.recv(1024)

if file_contents == b'File not found' :
	print("File not found on the server.")
else:
	print("File contents:\n",file_contents.decode())
	
	with open("received_" + file_name,'w') as file:
		file.write(file_contents.decode())
	print("File received and saved as 'received_" + file_name + "'")

client_socket.close()


