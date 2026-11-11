#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],k[505],a[500005],t[500005],dis[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
		for(ll j=1;j<=k[i];j++){
			for(ll p=1;p<=k[i];p++){
				if(j==p)continue;
				dis[a[j]][a[p]]=dis[a[p]][a[j]]=t[j]+t[p];
			}
		}
	}
	for(ll i=1;i<=m;i++)dis[i][i]=0;
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			for(ll p=1;p<=m;p++){
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}