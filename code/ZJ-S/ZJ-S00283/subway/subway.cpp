#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=2e4+5;
int c,n,m,d,q;
int w[M];
int a[M];
int t,tx[N][M];
bool vis[M];
struct node{
	int v;
	int num;
};
vector<node> vt[M];
int x,y;
long long mins;
void dfs(int now,int wd,long long cnt){
	if(now==y){
		mins=min(mins,cnt+w[y]+tx[wd][now]);
		return;
	}
	for(auto it:vt[now]){
		if(vis[it.v]){
			continue;
		}
		long long cnts=cnt;
		if(wd!=it.num){
			cnts+=tx[wd][now]+tx[it.num][now];
		}
		vis[it.v]=true;
		dfs(it.v,it.num,cnts);
		vis[it.v]=false;      
	}         
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t;
			tx[i][a[j]]=t;
			if(j>=2){
				vt[a[j]].push_back({a[j-1],i});
				vt[a[j-1]].push_back({a[j],i});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		mins=1e18;
		memset(vis,false,sizeof(vis));
		vis[x]=true;
		for(auto j:vt[x]){
			vis[j.v]=true;
			dfs(j.v,j.num,w[x]+tx[j.num][x]);
			vis[j.v]=false;
		}
		cout<<mins<<'\n';
	}
	return 0;
}