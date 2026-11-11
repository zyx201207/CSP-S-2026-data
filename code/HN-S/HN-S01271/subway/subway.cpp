#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+9;
int c,n,m,b,qq,d[N],sum,bb[N],qz,zz,k[N];
vector<vector<pair<int,int> > > a;
queue<pair<int,int> > q;
int bfs(int x){
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		if(x==zz) return y;
		for(int i=0;i<a[x].size();i++){
			if(bb[x]==1) continue;
			bb[x]=1;
			q.push({a[x][i].first,y+1});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>b>>qq;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int kk=k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
		}
	}
	while(qq--){
		cin>>qz>>zz;
		sum=d[qz]+d[zz];
		bb[qz]=1;
		q.push({qz,0});
		cout<<sum+bfs(qz)*a[1][1].second;
	}
	return 0;
}
