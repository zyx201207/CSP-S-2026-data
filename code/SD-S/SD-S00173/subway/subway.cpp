#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
ll v[M];
int k[M];
bool vis[N];
ll dis[N][N];
vector<pair<int,ll> >w[N],g[N],in[M];
void DIJ(int st){
	priority_queue<pair<ll,int> >q;
	memset(vis,0,sizeof(vis));
	memset(dis[st],0x3f,sizeof(dis[st]));
	dis[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(int i=0;i<g[now].size();i++){
			int to=g[now][i].first;
			ll w=g[now][i].second;
			if(dis[st][to]>dis[st][now]+w){
				dis[st][to]=dis[st][now]+w;
				q.push({-dis[st][to],to}); 
			}
		}
	}
}
int Main(){
	int x,y;
	ll tmp,ans=1e18;
	cin>>x>>y;
	for(int i=0;i<in[x].size();i++){
		for(int j=0;j<in[y].size();j++){
			tmp=in[x][i].second+in[y][j].second+dis[in[x][i].first][in[y][j].first];
			ans=min(ans,tmp);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			w[i].push_back({x,y});
			in[x].push_back({i,v[x]+y});
		}
		sort(w[i].begin(),w[i].end());
	}
	for(int i=1;i<=m;i++){
		ll w1,w2;
		for(int p=0;p<in[i].size();p++){
			for(int q=p+1;q<in[i].size();q++){
				w1=in[i][p].second-v[i];
				w2=in[i][q].second-v[i];
				g[in[i][p].first].push_back({in[i][q].first,w1+w2});
				g[in[i][q].first].push_back({in[i][p].first,w1+w2});
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll W=1e18;
		//	cout<<i<<' '<<j<<"\n";
			for(int p=0,q;p<k[i];p++){
				pair<int,ll>fnd;
				fnd.first=w[i][p].first,fnd.second=-1e18;
				q=lower_bound(w[j].begin(),w[j].end(),fnd)-w[j].begin();
			//	cout<<q<<' ';
				if(q<0||q>=k[j]) continue;
				if(w[i][p].first==w[j][q].first){
					W=min(W,w[i][p].second+w[j][q].second);
				}
			}
			if(W==1e18) continue;
		//	dis[i][j]=dis[j][i]=W;
			g[i].push_back({j,W});
			g[j].push_back({i,W});
		}
	}
	*/
	/*
	for(int i=1;i<=m;i++){
		cout<<i<<":";
		for(unsigned j=0;j<in[i].size();j++){
			cout<<in[i][j].first<<' '<<in[i][j].second<<'\n';
		}
		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		cout<<i<<":";
		for(unsigned j=0;j<g[i].size();j++){
			cout<<g[i][j].first<<" "<<g[i][j].second<<"\n";
		}
		cout<<"\n";
	}*/
	for(int i=1;i<=n;i++){
		DIJ(i);
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<"\n";
	}*/
	while(q--){
		Main();
	}
	return 0;
}
/*
//  É¾´óÑùÀý 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
