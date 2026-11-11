#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
vector<pair<int,int> > a[500005];
int f[505][505];
map<pair<int,int>,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			a[x].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			int x1=a[i][j].first,t1=a[i][j].second;
			for(int k=j+1;k<a[i].size();k++){
				int x2=a[i][k].first,t2=a[i][k].second;
				f[x1][x2]=f[x2][x1]=min(f[x1][x2],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(f[i][k]>=0x3f3f3f3f3f3f3f3f) continue;
			for(int j=1;j<=n;j++){
				if(f[k][j]>=0x3f3f3f3f3f3f3f3f) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(mp[{x,y}]){
			cout<<mp[{x,y}]<<'\n';
			continue;
		}
		int res=0x7f7f7f7f7f7f7f7f;
		for(auto i:a[x]){
			for(auto j:a[y]){
				res=min(res,w[x]+w[y]+i.second+j.second+f[i.first][j.first]);
			}
		}
		mp[{x,y}]=mp[{y,x}]=res;
		cout<<res<<'\n';
	}
	return 0;
}
