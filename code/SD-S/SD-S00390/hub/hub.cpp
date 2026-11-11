#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=5050;
const ll maxx=2e6+50;
const ll inf=0x3f3f3f3f;

int inline read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

ll c;

void solve(){
	int n=read(),k=read();
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
	}
	cout<<n-k<<"\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	c=read();
	ll T=read();
	
	for(ll i=1;i<=T;i++){
		solve();
	}
	return 0;
}
