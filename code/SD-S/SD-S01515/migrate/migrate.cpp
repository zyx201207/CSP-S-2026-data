#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
inline long long read(){
	long long res=0,f=1;char g=getchar();
	while(g<'0'||g>'9'){if(g=='-'){f=-1;}g=getchar();}
	while(g>='0'&&g<='9'){res=(res<<3)+(res<<1)+g-48;g=getchar();}
	return res*f;
}
int c,T;
long long a[2000010];
int main(){
	//愿那该死的荣耀尽归先锋部队 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
		while(T--){
			ll n=read(),d=read();
			for(int i=1;i<=n;i++)a[i]=read();
			ll x=a[2]-a[1];
			if(x>d){
				printf("0\n");
				continue;
			}
			ll v=d/x;
			ll b=v+2;
			if(b>n){
				printf("0\n");
				continue;
			}
			printf("%lld\n",n-b+1);
		}

	
	return 0;
}


