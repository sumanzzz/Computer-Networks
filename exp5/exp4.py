div = [1,0,0,0,1,0]
n = int(input("Enter the number of bits:"))
data= [int(input(f"enter bit {i + 1}:  ")) for i in range(n)]
m = len(div)

if n<m:
	print("Inavlid data")
else:
	cdata = data.copy()
	for i in range(m - 1):
		cdata.append(0)
	print("initial codeword:" ,cdata)
	
	for i in range(n):
		if cdata[i] == 1:
			for j in range(m):
				cdata[i + j] ^= div[j]
	for i in range(n, n + m-1):
		 data.append(cdata[i])
		 
	print("data to be transmitted:", data)
	
	ch = input("Introduce Error - Y_>YES, N->NO: ")
	if ch.upper() == "Y":
		p = int(input("enter the position to chnge bit (1-indexed):"))
		if p - 1 < 0 or p - 1 > n+m -2:
			print("Invalid Position!")
		else:
			data[p - 1] = 0 if data[p -1] == 1 else 1
	print("the message recived is:", data)
	
	for i in range(n):
		if data[i] == 1:
		 for j in range(m):
		 	data[i + j] ^= div[j]
	flag = True
	for i in data:
		if i == 1:
			flag = False
			break
	if flag:
		print("No Error -> Successfully Transfored")
	else:
		print("Error detected")
