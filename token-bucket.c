#include<stdio.h>
int main()
{
	int inp[25],nsec, cap,i,tok,ps=0,pl,pd=0,count = 0,token=0;
	printf("\nEnter the Bucket Size: ");
	scanf("%d",&cap);
	printf("\nEnter the No. token added every second: ");
	scanf("%d",&tok);
	printf("\nEnter The No. Of Seconds You Want To Stimulate: ");
	scanf("%d",&nsec);
	for(i=0;i<nsec;i++){
		printf("\nEnter the Size of the Packet Entering at %d  sec: ",i+1);
		scanf("%d",&inp[i]);
	}
	printf("\nSecond|Packet Recieved|Packet Sent|Packet Left|Packet Dropped|\n");
	printf("-----------------------------------------------------------------\n");
	for(i=0;i<nsec;i++){
		token=token+tok;
		if(cap<token){
			token=cap;
		}
		count+=inp[i];
		if(cap<count){
		printf("\nThe packet is more then size of bucket\n");
		break;
		}
		if(token>=count){
			token=token-count;
			ps=count;
			count=0;
		}
		else{
			pl=count;
		}
		printf("%d",i+1);
		printf("\t%d",inp[i]);
		printf("\t\t%d",ps);
		printf("\t\t%d",pl);
		printf("\t\t%d\n",pd);
		pl=0;
		ps=0;
	}
	for(;count!=0;i++){
		token=token+tok;
		if(cap<token){
			token=cap;
		}
		if(cap<count){
		printf("\nThe packet is more then size of bucket\n");
		break;
		}
		if(token>=count){
			token=token-count;
			ps=count;
			count=0;
		}
		else{
			pl=count;
		}
		printf("%d",i+1);
		printf("\t%d",inp[i]);
		printf("\t\t%d",ps);
		printf("\t\t%d",pl);
		printf("\t%d\n",pd);
		pl=0;
		ps=0;
	}
	printf("\nThe No. of token left in Bucket is : %d",token);
}

