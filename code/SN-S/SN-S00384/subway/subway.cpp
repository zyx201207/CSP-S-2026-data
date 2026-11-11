#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[500010],minn[500010];
vector<int> a[510],t[510];
vector<pair<int,int> > rin[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long t1,t2;
			cin>>t1>>t2;
			rin[t1].push_back({i,t2});
			a[i].push_back(t1);
			t[i].push_back(t2);
		}
	}
	while(q--){
		int beg,ed;
		cin>>beg>>ed;
		for(int i=1;i<=m;i++){
			minn[i]=1e18;
		}
		queue<pair<int,int> > qq;
		qq.push({beg,0});
		while(!qq.empty()){
			int t1=qq.front().first,t2=qq.front().second;
			qq.pop();
			if(t2>minn[t1]){
				continue;
			}
			minn[t1]=t2;
			for(int i=0;i<rin[t1].size();i++){
				for(int j=0;j<a[rin[t1][i].first].size();j++){
					if(a[rin[t1][i].first][j]==t1){
						continue;
					}
					if(t2+t[rin[t1][i].first][j]+rin[t1][i].second<minn[a[rin[t1][i].first][j]]){
						minn[a[rin[t1][i].first][j]]=t2+t[rin[t1][i].first][j]+rin[t1][i].second;
						qq.push({a[rin[t1][i].first][j],t2+t[rin[t1][i].first][j]+rin[t1][i].second});
					}
				}
			}
		}
		cout<<minn[ed]+w[beg]+w[ed]<<"\n";
	}
	return 0;
}
