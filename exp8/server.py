import socket
import re

localIP = "127.0.0.1"
localPort = 20001
bufferSize = 1024

UDPserverSocket = socket.socket(family=socket.AF_INET,type=socket.SOCK_DGRAM)
UDPserverSocket.bind((localIP,localPort))

print("UDP server up and listening...")

while True:
    bytesAddressPair = UDPserverSocket.recvfrom(bufferSize)
    expression = bytesAddressPair[0].decode()
    client_address = bytesAddressPair[1]
    
    num1,num2 = re.split(r'\+|-|\*|/|%',expression.replace(' ',''))
    num1 = float(num1)
    num2  =float(num2)
    
    result = 0
    
    if '+' in expression:
        result = num1 + num2
    elif '-' in expression:
        result = num1 - num2
    elif '*' in expression:
        result = num1 * num2
    elif '/' in expression:
        if num2 == 0:
            result = 'Division by zero'
        else:
            result = num1 / num2
    
    elif '%' in expression:
        if num2 == 0:
            result = 'Division by zero'
        else:
            result = num1 % num2
    else:
        result= 'Invalid Expression'
        
        
    print("Equation from client",client_address,":",expression)
    print("Result to client:",result)
    
    UDPserverSocket.sendto(str(result).encode(),client_address)
