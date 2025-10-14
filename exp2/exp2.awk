BEGIN{
	#counters for packets
	ctcp = 0;
	cudp = 0;
	
	#variables for throughput
	sSize = 0;
	startTime = 5.0;
	stopTime = 0.1;
	Tput = 0;
}
{
	#identify TCP/UDP packets
	pkt = $5;
	if(pkt == "cbr") {cudp++}
	if(pkt == "tcp") {cudp++}
	
	#throughput calculation
	event = $1;
	time = $2;
	size = $6;
	
	if(event == "+"){
		if(time<startTime){
			startTime = time;
		}
	}
	if(event == "r"){
		if(time > stopTime){
			stopTime = time;
		}
		sSize += size;
	}
	
	Tput = (sSize / (stopTime - startTime))*(8/1000)
	printf("%f\t%2f\n",time,Tput);
}
END{
	printf("\n----------\n");
	printf("No of packets sent:\n");
	printf("tcp:%d \n",ctcp);
	printf("udp:%d \n",cudp);
	printf("\n----------\n");
	
}
