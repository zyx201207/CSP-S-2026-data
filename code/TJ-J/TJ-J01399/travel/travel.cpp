#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1[11],a2[11],b1[11],b2[11];
	scanf("%s",a1+1);
	scanf("%s",a2+1);
	scanf("%s",b1+1);
	scanf("%s",b2+1);
	int a=1,b=1,c=1,d=1;
	bool flag=true;
	for(int i=1;i<=2;i++){
		if(a1[i]!=b1[i]){
			flag=false;
			break;
		}
	}
	if(!flag){
		printf("0000");
		return 0;
	}else{
		if(a2[2]!=b2[2]){
			printf("1000");
			return 0;
		}else{
			if(!(((a2[3]=='A' || a2[3]=='B' || a2[3]=='C') && (b2[3]=='A' || b2[3]=='B' || b2[3]=='C')) || ((a2[3]=='D' || a2[3]=='F') && (b2[3]=='D' || b2[3]=='F')))){
				printf("1100");
				return 0;
			}else{
				if(abs(a2[3]-b2[3])!=1){
					printf("1110");
					return 0;
				}else{
					printf("1111");
				}
			}
		}
	}
	return 0;
}
