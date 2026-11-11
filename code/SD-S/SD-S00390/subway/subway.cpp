#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=5e5+50;
const ll inf=0x3f3f3f3f;

int inline read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

ll c,n,m,d,q;
ll w[maxn*2];
ll g[1010][1010];
ll vis[1010][1010];
ll a[maxn*2],t[maxn*2];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read();n=read();m=read();d=read();q=read();
	
	for(ll i=1;i<=m;i++)w[i]=read();
	
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			g[i][j]=(i==j)?0:inf;
		}
	}
	
	
	for(ll i=1;i<=n;i++){
		ll k=read();
		for(ll j=1;j<=k;j++){
			a[j]=read();t[j]=read();
		}
		for(ll j=1;j<=k;j++){
			for(ll h=1;h<=k;h++){
				g[a[h]][a[j]]=g[a[j]][a[h]]=min(g[a[j]][a[h]],t[j]+t[h]);
			}
		}
	}
	
	for(ll k=1;k<=m;k++){
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	
	for(ll i=1;i<=q;i++){
		ll x=read(),y=read();
		cout<<g[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
