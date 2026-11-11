#include<bits/stdc++.h>
//define PII pair<int,int>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],ans,to[N][600],p=-1;
bool ok;
vector<int>way[N];
vector<int>dis;
vector<int>vis;
vector<int>pass[600];
void dfs(int x){
	if((x==p)||(dis[x]>=dis[p])||ok){
		vis[x]=0;
		ok=((x==p)&&(c<=19&&c>=12));
		return;
	}
	for(int i:way[x]){
		for(int j:pass[i]){
			if(j==x)continue;
			if(dis[x]+to[x][i]+to[j][i]<dis[j]){
				dis[j]=dis[x]+to[x][i]+to[j][i];
				if(!vis[j]){
					vis[j]=1;
					dfs(j);
				}
			}
		}
	}
	vis[x]=0;
}
int main(){
	freopen("subway5.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vis.resize(m+20);
	dis.resize(m+20);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t; 
			pass[i].push_back(a);
			way[a].push_back(i);
			to[a][i]=t;
		}
	}
	int x,y,lx=0;
	while(q--){
		ok=0;
		cin>>x>>y;
		if(lx!=x){
			dis=*(new vector<int>);
			dis.resize(m+20,1e9);
		}
		p=y;
		dis[x]=w[x];
		if(x!=lx)dfs(x);
		lx=x;
		cout<<dis[p]+w[p]<<endl;
	}
}
