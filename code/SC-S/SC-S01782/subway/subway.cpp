#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 500005
#define N 505
#define D 25
#define Q 100005
ll c,n,m,d,q;
ll w[M],num[M],t[M][D],sub[M][D],f[N][N];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=n;i++) f[i][i]=0;
	
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,tt;
			cin>>a>>tt;
			t[a][++num[a]]=tt;
			sub[a][num[a]]=i;
		}
	}
	
	for(ll i=1;i<=m;i++){
		if(num[i]<=1) continue;
		for(ll j=1;j<=num[i];j++)
			for(ll k=j+1;k<=num[i];k++){
				ll st=sub[i][j],ed=sub[i][k];
				f[st][ed]=min(t[i][j]+t[i][k],min(f[st][ed],f[ed][st]));
				f[ed][st]=f[st][ed];
			}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			if(i==k) continue;
			for(ll j=1;j<=n;j++){
				if(i==j||j==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	while(q--){
		ll ans=0,x,y,mmin=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		ans=ans+w[x]+w[y];
		for(ll i=1;i<=num[x];i++){
			ans+=t[x][i];
			for(ll j=1;j<=num[y];j++){
				ans+=t[y][j];
				ans+=f[sub[x][i]][sub[y][j]];
				mmin=min(mmin,ans);
				ans-=t[y][j];
				ans-=f[sub[x][i]][sub[y][j]];
			}
			ans-=t[x][i];
		}
		cout<<mmin<<'\n';
	}
	return 0;
}