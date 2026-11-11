#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int a,ac,b,bc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	a=(s[0]-'0')*10+s[1]-'0';
	ac=s[2]-'A';
	b=(ss[0]-'0')*10+ss[1]-'0';
	bc=ss[2]-'A';
//	printf("%d %d %d %d",a,ac,b,bc);
	if(c!=cc){
		printf("0000");
	}
	else{
		if(a!=b){
			printf("1000");
		}
		else{
			if(!(ac<3&&bc<3)&&!(ac>=3&&bc>=3)){
				printf("1100");
			}
			else{
				if(abs(ac-bc)!=1){
					printf("1110");
				}
				else{
					printf("1111");
				}
			}
		}
	}
	return 0;
}
