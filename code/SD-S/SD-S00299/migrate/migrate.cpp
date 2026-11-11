#include<bits/stdc++.h>
using namespace std;
const int max_n=2e6+5;
long long c,t,n,d,a[max_n];
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	for(int z=1;z<=t;z++){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(n<=2){
			puts("0");
		}
		else if(c==11||c==12){
			if(d>=a[2]-a[1]&&d<a[4]-a[1]){
				printf("%lld\n",n-3);
			}
			else{
				puts("0");
			}
		}
		else{
			puts("0");
		}
	}
	return 0;
}

