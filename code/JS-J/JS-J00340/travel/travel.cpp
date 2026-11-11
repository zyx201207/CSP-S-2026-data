#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	if(a==d){
		if(s[0]==f[0]&&s[1]==f[1]){
			if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(f[2]=='D'||f[2]=='F'))){
				if(abs(s[2]-f[2])==1){
					printf("1111");
				}else{
					printf("1110");
				}
			}else{
				printf("1100");
			}
		}else{
			printf("1000");
		}
	}else{
		printf("0000");
	} 
	return 0;
}
