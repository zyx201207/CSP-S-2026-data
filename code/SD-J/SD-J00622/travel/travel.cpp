#include<bits/stdc++.h>
using namespace std;
char a[5],b[5];
long long n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s",a);
	scanf("%lld",&m);
	scanf("%s",b);
	if(n==m){
		if(a[1]==b[1]&&a[0]==b[0]){
			if(a[2]=='D'&&b[2]=='F'||b[2]=='D'&&a[2]=='F'){
				printf("1111");
			}
			else if(a[2]=='C'&&b[2]=='B'||a[2]=='C'&&b[2]=='A'){
				if(b[2]=='B'){
					printf("1111");
				}
				else{
					printf("1110");
				}
			}
			else if(a[2]=='B'&&b[2]=='C'||a[2]=='A'&&b[2]=='C'){
				if(a[2]=='B'){
					printf("1111");
				}
				else{
					printf("1110");
				}
			}
			else if(a[2]=='C'&&b[2]=='A'||a[2]=='B'&&b[2]=='A'){
				if(a[2]=='B'){
					printf("1111");
				}
				else{
					printf("1110");
				}
			}
			else if(a[2]=='A'&&b[2]=='C'||a[2]=='A'&&b[2]=='B'){
				if(b[2]=='B'){
					printf("1111");
				}
				else{
					printf("1110");
				}
			}
			else{
				printf("1100");
			}
		}
		else{
			printf("1000");
		}
	}
	else{
		printf("0000");
	}
	return 0;
} 
