#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e6+6;

inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1ll)+(x<<3ll)+(ch^48);
	return x*f;
}

inline void write(ll x){
	if(x<0){
		putchar('-'),write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}

ll c,n,k,u,v;
vector<ll>edge[maxn];

inline void solve(){
	n=read(),k=read();
	rep(i,1,n-1){
		u=read(),v=read();
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	cout<<1<<'\n';
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    c=read();
    ll _=read();
    while(_--) solve();
	return 0;
}

