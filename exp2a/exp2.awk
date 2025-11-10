BEGIN{
	ctcp = 0;
	cudp = 0;
	
	sSize = 0;
	
	startTime = 5.0;
	stopTime = 0.1;
	throughput = 0;
}

{
	pkt = $5;
	if(pkt =="cbr") {
		cudp++;
	}
	if(pkt =="tcp"){
		ctcp++;
	}
	
	event = $1
	time = $2;
	size = $6;
	
	if(event =="+"){
		if(time < startTime){
			startTime = time;
		}
	}
	if(event == "r"){
		if(time > stopTime){
			stopTime = time;
		}
		sSize += size;
	}
	throughput = (sSize/(stopTime - startTime))*(8/100);
	printf("%f\t%2f\n",time,throughput);
}

END{
	printf("\n-------------------\n");
	printf("No. of packets sent:\n");
	printf("TCP:%d\n",ctcp);
	printf("UDP:%d\n",cudp);
}
