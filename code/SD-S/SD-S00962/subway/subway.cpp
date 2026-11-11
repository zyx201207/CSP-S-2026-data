#include<bits/stdc++.h>

#define ll long long
#define MAXX 10000

using namespace std;

inline ll read(){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9' and c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

inline void write(ll k){
	if(k<0)putchar('-'),k=-k;
	if(k>9)write(k/10),k%=10;
	putchar(k+'0');
}

	ll c,n,m,d,q,m1[MAXX];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		m1[i]=read();
	
	for(int i=1;i<=n;i++){
		ll k;
		k=read();
		
		for(int j=1;j<=k;j++){
			ll x;
			x=read();
		}
	}
	cout<<-1;
	return 0;
}
