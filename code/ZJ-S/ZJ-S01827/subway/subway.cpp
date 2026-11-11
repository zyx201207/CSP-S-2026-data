#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,T,w[500005],k[505],vis[505],ans[505];
vector<pair<int,int> > g[505];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<int> a[500005];
vector<int> t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int o1,o2;
			cin>>o1>>o2;
			a[i].push_back(o1);
			t[i].push_back(o2);	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			for(int u=j+1;u<k[i];u++){
				g[j].push_back(make_pair(t[i][a[i][j]-1]+t[i][a[i][u]-1],u));
				g[u].push_back(make_pair(t[i][a[i][j]-1]+t[i][a[i][u]-1],j));
			}
		}
	}
	while(T--){
		memset(ans,0x3f,sizeof(ans));
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		ans[x]=0;
		q.push(make_pair(0,x));
		while(!q.empty()){
			pair<int ,int> h=q.top();
			q.pop();
			int ww=h.first;
			int tt=h.second;
			if(vis[tt])
				continue;
			vis[tt]=1;
			for(int i=0;i<g[tt].size();i++){
				pair<int ,int> ss=g[tt][i];
				if(ans[ss.second]>ww+ss.first){
					ans[ss.second]=ww+ss.first;
					for(int j=0;j<g[ss.second].size();j++)
						q.push(g[ss.second][j]);
				}
			}
		}
		while(q.size())
			q.pop();
		cout<<ans[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}