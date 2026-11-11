#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
   string a,b,c,d;
   cin>>a>>b>>c>>d;
   if(a[0]==c[0]&&a[1]==c[1]){
   	if(b[0]==d[0]&&b[1]==d[1]){
   		if(b[2]=='F'||b[2]=='D'){
   			if(c[2]=='F'||c[2]=='D'){
   			printf("%d",1111);
			   }else{
			   	printf("%d",1110);
			   }
		   }else if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		   
		   		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		   			if(b[2]+1==d[2]||d[2]+1==b[2]){
		   					printf("%d",1111);
					   }else{
					   	printf("%d",1110);
					   }
		}
			   }else{
			   	printf("%d",1110);
			   }
	   }else{
	   	  printf("%d",1);
	   	for(int i=1;i<4;i++){
	   		printf("%d",0);
		   }	 
	   }
   }else{
   	for(int a=1;a<5;a++){
   		printf("%d",0);
	   }
   }	
	fclose(stdin);
	fclose(stdout);

	return 0;
}