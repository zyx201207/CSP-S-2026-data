#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,f[505][505],w[500005];
vector<pair<int,int>>v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			v[y].push_back({i,z});
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto j:v[i]){
			for(auto k:v[i]){
				if(j>=k){
					continue;
				}
				f[j.first][k.first]=min(f[j.first][k.first],j.second+k.second);
				f[k.first][j.first]=f[j.first][k.first];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=9e18;
		cin>>x>>y;
		for(auto j:v[x]){
			for(auto k:v[y]){
				ans=min(ans,j.second+k.second+f[j.first][k.first]+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 