#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500001],k[501],a[501][501];
struct P{
	int x,y;
};
vector<P>e[500001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=1000000000000000000;
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=m;i++){
		for(P j:e[i]){
			for(P k:e[i]){
				if(j.x==k.x)continue;
				a[j.x][k.x]=a[k.x][j.x]=k.y+j.y;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		} 
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int mi=1000000000000000000;
		for(P i:e[l]){
			for(P j:e[r]){
				mi=min(mi,a[i.x][j.x]+i.y+j.y);
			}
		}
		cout<<mi+w[l]+w[r]<<"\n";
	}
	return 0;
}
