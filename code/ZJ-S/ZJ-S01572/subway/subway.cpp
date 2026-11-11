#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
vector < pair < int , long long > >e[500005];//每个站有哪几个地铁线路经过 
long long w[500005];
int k[505];
vector< pair < int , long long > >v[505];//每条地铁线路可以直接转到哪一条 
long long ct[505][505];
map < int , long long > mp[505];
void init(){
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) ct[i][j]=2e18;
	}
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
//		cout<<i<<'$';
		scanf("%d",&k[i]);
		int x;
		long long t;
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&x,&t);
	//		cout<<x<<' '<<t<<"#";
			mp[i][x]=t;
	//		cout<<i<<' '<<x<<' '<<t<<"&  ";
			for(int p=0;p<e[x].size();p++){
				long long f=t+e[x][p].second;
				int to=e[x][p].first;
				ct[to][i]=ct[i][to]=min(ct[to][i],f);
		//		cout<<i<<' '<<to<<"%  ";
			}
			e[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ct[i][j]<2e17){
				v[i].push_back({j,ct[i][j]});
				v[j].push_back({i,ct[i][j]});
			//	cout<<i<<' '<<j<<"*  ";
			}
		}
	}	
}
bool vis[505];
long long g[505][505];
void check(int s){
	priority_queue< pair < long long , int > ,vector< pair < long long , int > > , greater< pair < long long , int > > > q;
	for(int i=1;i<=n;i++) vis[i]=0;
	q.push({0,s});
	int num=0;
	int now;
	long long cost;
	while(!q.empty() && num<n){
		now=q.top().second,cost=q.top().first;
		q.pop();
		if(vis[now]) continue;
		vis[now]=1;
		num++;
		g[s][now]=cost;
		for(int i=0;i<v[now].size();i++){
			if(!vis[v[now][i].first]){
				q.push({v[now][i].second+cost,v[now][i].first});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	for(int i=1;i<=n;i++) check(i);
	int x,y;
	while(qq--){
		scanf("%d%d",&x,&y);
		long long ans=2e18;
		int a,b;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				a=e[x][i].first,b=e[y][j].first;
				ans=min(ans,g[a][b]+e[x][i].second+e[y][j].second);
			}
		}
		if(qq) printf("%lld\n",ans+w[x]+w[y]);
		else cout<<ans+w[x]+w[y];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
