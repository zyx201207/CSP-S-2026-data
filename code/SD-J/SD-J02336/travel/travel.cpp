#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xrcx,xrzw,xxcx,xxzw;
//	scanf("%s%s%s%s",&xrcx,&xrzw,&xxcx,&xxzw);
	cin>>xrcx>>xrzw>>xxcx>>xxzw;
	int xrc=xrcx[0]*10+xrcx[1];
	int xxc=xxcx[0]*10+xxcx[1];
	int xrz=xrzw[0]*10+xrzw[1];
	char xrr=xrzw[2];
	int xxz=xxzw[0]*10+xxzw[1];
	char xxx=xxzw[2];
	if(xrc==xxc){
		printf("1");
		if(xrz==xxz){
			printf("1");
			if(xrr=='A'){
				if(xxx=='B'){
					printf("11");
					return 0;
				}
				else if(xxx=='C'){
					printf("10");
					return 0;
				}
				else{
					printf("00");
					return 0;
				}
			}
			if(xrr=='B'){
				if(xxx=='A'||xxx=='C'){
					printf("11");
					return 0;
				}
				else{
					printf("00");
					return 0;
				}
			}
			if(xrr=='C'){
				if(xxx=='B'){
					printf("11");
					return 0;
				}
				else if(xxx=='A'){
					printf("10");
					return 0;
				}
				else{
					printf("00");
					return 0;
				}
			}
			if(xrr=='D'){
				if(xxx=='E'){
					printf("11");
					return 0;
				}
				else{
					printf("00");
					return 0;
				}
			}
			if(xrr=='E'){
				if(xxx=='D'){
					printf("11");
					return 0;
				}
				else{
					printf("00");
					return 0;
				}
			}	
		} 
		else{
			printf("000");
			return 0;
		}		
	} 
	else{
		printf("0000");
		return 0;
	}
	return 0;
}
