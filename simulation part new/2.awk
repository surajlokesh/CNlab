BEGIN{
tcpdropped=0;
udpdropped=0;
tcpcount=0;
udpcount=0;
}
{
 if($5=="tcp"){
tcpcount++;
if($1=="d")
{
tcpdropped++;
}
printf("%s\t%s\n",$5,$11);
}
if($5=="cbr")
{
  udpcount++;
  if($1=="d")
  {
    udpdropped++;
  }
}
}
END{
  printf("the number of tcp packets are %d\n",tcpcount);
  printf("the number of udp packets are %d\n",udpcount);
   printf("the number of tcp packets dropped are %d\n",tcpdropped);
    printf("the number of udp packets dropped are %d\n",udpdropped);
  printf("the packet delivery function for TCP are %f\n",(tcpcount-tcpdropped)/tcpcount);

  printf("the packet delivery function for UDP are %f\n",(udpcount-udpdropped)/udpcount);
}



