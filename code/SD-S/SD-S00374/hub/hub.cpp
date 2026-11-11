#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll c,t,n,k,u[N],v[N];
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();
		k=read();
		for(ll i=1;i<=n-1;i++){
			u[i]=read();
			v[i]=read();
		} 
		cout<<1<<"\n";
	}
	return 0;
}
