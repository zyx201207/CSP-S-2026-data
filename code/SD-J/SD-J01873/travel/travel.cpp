#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c",&a1,&a2,&c1);
	scanf("%d%d%c",&b1,&b2,&c2);
	if(a1==b1){
		printf("1");
		if(a2==b2){
			printf("1");
			if(c1>='A' && c1<='C'&& c2>='A' && c2<='C' || c1>='E' && c1<='F' && c2>='E' && c2<='F'){
				printf("1");
				if(abs(c1-c2)==1 && (c1!='D' || c2!='C' ) &&(c2!='D' || c1!='C')){
					printf("1");
				}else{
					printf("0");
				}
			}
			else{
				printf("00");
				return 0;
			}
		}
		else{
			printf("000");
			return 0;
		}
	}else{
		printf("0000");
		return 0;
	}
	return 0;
} 
