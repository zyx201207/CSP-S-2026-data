#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[505][20005],t[505][20005];
vector<pair<int,int> > f[505];
priority_queue<pair<int,int> >s;
int ta[500005],w[500005],k[505];
bool vis[500005];
void dfs(int k){
	s.push({0,k});
	ta[k]=0;
	while(!s.empty()){
		pair<int,int> d=s.top();
		int u=d.second;
		s.pop();
		vis[u]=0;
		for(pair<int,int> i:f[u]){
			int x=i.first,y=i.second;
			if(ta[x]>y+d.first){
				ta[x]=y+d.first;
				if(!vis[x]){
					vis[x]=1;
					s.push({ta[x],x});
				}
			}
		}
	}
}
int d,q,c;
signed main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dis.push_back(0);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=k[i];j++){
			for(int o=1;o<=k[i];o++){
				if(j!=o)f[a[i][j]].push_back({a[i][o],a[i][j]+t[i][o]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(ta,0x3f,sizeof ta);
		dfs(x);
		cout<<ta[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
