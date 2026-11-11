#include<bits/stdc++.h>
using namespace std;
typedef long long Int;
typedef pair<Int,Int> pir;
#define fi first
#define se second

Int c,n,m,d,q,w[500005],mp[505][505];
vector<pir>a[500005];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(Int i=1;i<=m;i++)cin>>w[i];
	for(Int i=1;i<=n;i++){
		Int k;
		cin>>k;
		for(Int j=1;j<=k;j++){
			Int v,val;
			cin>>v>>val;
			a[v].push_back({i,val});
		}
	}
	memset(mp,0x3f3f3f3f,sizeof mp);
	for(Int i=1;i<=n;i++)mp[i][i]=0;
	for(Int i=1;i<=m;i++){
		for(pir e1:a[i]){
			for(pir e2:a[i]){
				mp[e1.fi][e2.fi]=mp[e2.fi][e1.fi]=min(mp[e1.fi][e2.fi],e1.se+e2.se);
			}
		}
	}
	for(Int k=1;k<=n;k++){
		for(Int i=1;i<=n;i++){
			for(Int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
			}
		}
	}
	for(Int i=1;i<=q;i++){
		Int x,y,ans=1e18;
		cin>>x>>y;
		for(pir e1:a[x]){
			for(pir e2:a[y]){
				ans=min(ans,e1.se+mp[e1.fi][e2.fi]+e2.se);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}

	return 0;
}
