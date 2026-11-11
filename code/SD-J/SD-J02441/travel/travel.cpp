#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
char a[100005];
char b[100005];
char c[100005];
char d[100005];
int n,m,p,q;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int la=strlen(a);
	int lb=strlen(b);
	int lc=strlen(c);
	int ld=strlen(d);
	if(la!=lc){
		printf("0000");
		return 0;
	}
	else{
		if(a[0]!=c[0]||a[1]!=c[1]||a[2]!=c[2]){
			printf("0000");
			return 0;
		}
		else{
			if(lb!=ld){
				printf("1000");
				return 0;
			}
			else{
				if((lb==3&&(b[0]!=d[0]||b[1]!=d[1]))||(lb==4&&(b[0]!=d[0]||b[1]!=d[1]||b[2]!=d[2]))){
					printf("1000");
					return 0;
				}
				else{
					char x=b[lb-1],y=d[ld-1];
					if(x=='A'||x=='B'||x=='C'){
						if(y=='A'||y=='B'||y=='C'){
							printf("111");
							if(x=='A'&&y=='B'){
								printf("1");
								return 0;
							}
							else if(x=='B'&&(y=='A'||y=='C')){
								printf("1");
								return 0;
							}
							else if(x=='C'&&(y=='B')){
								printf("1");
								return 0;
							}
							else{
								printf("0");
								return 0;
							}
						}
						else{
							printf("1100");
							return 0;
						}
					}
					else{
						if(y=='D'||y=='F'){
							printf("1111");
							return 0;
						}
						else{
							printf("1110");
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
} 
































