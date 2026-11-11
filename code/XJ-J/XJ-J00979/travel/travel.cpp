#include <bits/stdc++.h>
using namespace std;
//ios::sync_with_stdio(false);
char a,b;
int e,f,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c",&e,&f,&a);
	scanf("%d %d%c",&c,&d,&b);
	if(e==c){
		printf("1");
		if(f==d){
			printf("1");
			if(a<'D'&&b<'D'){
				printf("1");
				if(a==b+1||b==a+1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}