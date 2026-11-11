#include<bits/stdc++.h>
using namespace std;
string ss0,ss1,ss2,ss3;
int main(){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		cin>>ss0>>ss1>>ss2>>ss3;
		if(ss0!=ss2){
			printf("0000");
			return 0;
		}
		else printf("1");
		if(ss1[0]==ss3[0]&&ss1[1]==ss3[1]){
			printf("1");
			if(((ss1[2]>='A'&&ss1[2]<='C')&&(ss3[2]>='A'&&ss3[2]<='C'))||((ss1[2]>='D'&&ss1[2]<='F')&&(ss3[2]>='D'&&ss3[2]<='F'))){
				printf("1");
				if((ss1[2]-1==ss3[2])||(ss3[2]-1==ss1[2])){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
		return 0;
}
