#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],f[500005],dis[500005];
vector<int> t[505],s[505];
vector<pair<int,int> > l[50005];

void bfs(int st){
	priority_queue<pair<int,int> > pq;
	pq.push({-a[st],st});
	while(!pq.empty()){
		int pos=pq.top().second;
		int tim=pq.top().first;
		f[pos]=1;
		pq.pop();
		for(int i=0;i<l[pos].size();++i){
			int u=l[pos][i].first;
			int w=l[pos][i].second;
			if(f[u]==1){
				continue;
			}
			if(w-tim<dis[u]){
				dis[u]=w-tim;
				pq.push({-w+tim,u});
			}
		}
	}
	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		t[i].push_back(0);
		s[i].push_back(0);
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin>>x>>y;
			t[i].push_back(y);
			s[i].push_back(x);
		}
		for(int j=1;j<=k;++j){
			for(int kk=j+1;kk<=k;++kk){
				l[s[i][j]].push_back({s[i][kk],t[i][j]+t[i][kk]});
				l[s[i][kk]].push_back({s[i][j],t[i][j]+t[i][kk]});
			}
		}
	}
	while(q--){
		for(int i=1;i<=n;++i){
			dis[i]=0x3f3f3f3f;
		}
		int st,en;
		cin>>st>>en;
		bfs(st);
		cout<<dis[en]<<'\n';
	}
	return 0;
}
