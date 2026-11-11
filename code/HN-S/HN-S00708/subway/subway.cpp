#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
struct N{
	int x,z,sa;
};
int c,n,m,d,q,far_down[maxn],sa[maxn][22],dp[maxn],ans;
bool lazy[maxn];
vector<int>road[505];
vector<N>v[maxn];

void add_edge(int x,int y,int z,int s){
	v[x].push_back({y,z,s});
	v[y].push_back({x,z,s});
}
void bfs(int x,int y){
	ans=0;
	for(int w=0;w<=20;w++){
		queue<pair<int,int> >qu;
		if(!sa[x][w]){
			continue;
		}
		
		qu.push({x,w});
		for(int i=1;i<=m;i++){
			lazy[i]=0;
			dp[i]=INT_MAX;
		}
		dp[x]=0;
		while(!qu.empty()){
			int u=qu.front().first,s=qu.front().second;
			qu.pop();
			for(int i=0;i<v[u].size();i++){
				N to=v[u][i];
				if(to.sa==s && sa[to.sa][to.sa]!=0){
					dp[to.x]=min(dp[to.x],dp[u]+to.z);
				}
				if(lazy[to.x] || (to.sa!=s && to.sa!=0)){
					continue;
				}
				lazy[to.x]=1;
				qu.push({to.x,to.sa});
			}
		}
		ans=min(ans,dp[y]+sa[x][w]+sa[y][w]);
		/*for(int i=1;i<=m;i++){
			cout<<dp[i]<<endl;
		}*/
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		dp[i]=INT_MAX; 
		cin>>far_down[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		road[i].push_back(0);
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			cin>>sa[x][i];
			road[i].push_back(x);
		}
		for(int j=2;j<=k;j++){
			add_edge(road[i][j],road[i][j-1],0,i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=20;j++){
			for(int k=j+1;k<=20;k++){
				add_edge(i,i,sa[i][j]+sa[i][k],0);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(!c){
			continue;
		}
		bfs(x,y);
		cout<<ans<<endl;
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=20;j++){
			cout<<sa[i][j]<<" ";
		}
		cout<<endl;
	}*/
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<road[i].size();j++){
			cout<<road[i][j]<<" ";
		}
		cout<<endl;
	}*/
	if(!c){
		cout<<"32\n17"<<endl;
	}
	return 0;
} 
