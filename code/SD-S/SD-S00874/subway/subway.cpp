#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long

struct node{
	int num;
	int tim;
	int line;
};

int k[505],a[505][50005],t[505][50005],w[50005];

vector<node> e[50005];

int c,n,m,d,q;
int vis[50005];
int dis[50005];

void BFS(int begin,int end){
	queue<pii> q;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	
	q.push({begin,-1});
	vis[begin]=1;
	dis[begin]=w[begin];
	
	while(!q.empty()){
		pii t=q.front();
		q.pop();
		
		if(t.first==end){
			return;
		} 
		for(auto i:e[t.first]){
			if(!vis[i.num]){
				vis[i.num]=1;
				q.push({i.num,i.line});
				if(i.line!=t.second)
					dis[i.num]+=e[t.second][i.num].tim+e[i.num][i.line].tim;
			}
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
		for(int j=2;j<=k[i];j++){
			e[a[i][j-1]].push_back({a[i][j],t[i][j],k[i]});
			e[a[i][j]].push_back({a[i][j-1],t[i][j-1],k[i]});
		}
	}
	for(int i=1;i<=q;i++){
		int xi,yi;
		cin>>xi>>yi;
		
		//BFS(xi,yi);
		
		cout<<dis[yi]<<endl;
	}
	
	return 0;
}
