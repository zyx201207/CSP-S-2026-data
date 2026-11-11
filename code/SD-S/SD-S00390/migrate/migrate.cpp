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
ll dis[maxn][maxn];
ll vis[maxn][maxn];

ll n,d;
ll a[maxx];
void solve(){
	n=read();d=read();
	for(ll i=1;i<=n;i++)a[i]=read();
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dis[i][j]=(i==j)?0:inf;
			vis[i][j]=1;
		}
	}
	
	ll l=1,r=1;
	for(ll i=1;i<=n;i++){
		while(l<=i&&a[i]-a[l]>d)l++;
		while(r<=n&&a[r]-a[i]<d)r++;
		for(ll j=l;j<=r;j++){
			dis[j][i]=dis[i][j]=min(dis[i][j],abs(a[i]-a[j]));
		}
	}
	
	ll ans=0;
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(dis[i][j]==(dis[i][k]+dis[k][j])){
				   vis[i][j]++;	
				}
				if(dis[i][j]>(dis[i][k]+dis[k][j])){
					vis[i][j]=1;
				}
				dis[i][j]=min(dis[i][j],dis[i][j]+dis[k][j]);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[i][j]==2&&dis[i][j]!=inf){
				ans++;
			}
		}
	}
	
	cout<<ans/2<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read();
	ll T=read();
	
	for(ll i=1;i<=T;i++){
		solve();
	}
	return 0;
}
