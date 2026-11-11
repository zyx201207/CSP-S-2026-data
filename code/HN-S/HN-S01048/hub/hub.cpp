#include <bits/stdc++.h>
using namespace std;
const int N=110;
int c,t,n,k,ans,d[N],mx;
int dfn[N][N];
bool vis[N];
bool cnt[N][N];
int f[N];
vector <int> v;
int find(int x){
	if(f[x]!=x) return f[x]=find(f[x]);
	return x;
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb) return;
	f[fa]=fb;
}
void dfs(int l){
	if(l>n){
		if(v.size()!=k) return;
		for(int i=1;i<=n;i++){
			d[i]=1e9;
			f[i]=i;
			vis[i]=0;
		}
		for(int i=1;i<v.size();i++){
			for(int j=0;j<i;j++){
				if(find(v[i])!=find(v[j])&&cnt[v[i]][v[j]]) merge(v[i],v[j]);
			}
		}
		int h=0;
		for(int i=0;i<v.size();i++){
			if(!vis[find(v[i])]) h++;
			vis[find(v[i])]=1;
		}
		if(h>2) return;
		for(int i=1;i<=n;i++){
			for(int j=0;j<v.size();j++){
				d[i]=min(d[i],dfn[i][v[j]]);
			}
			
		}
		
		mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,d[i]);
		}
		ans=min(ans,mx);
		return;
	}
	v.push_back(l);
	dfs(l+1);
	v.pop_back();
	dfs(l+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		v.clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dfn[i][j]=1e9;
				cnt[i][j]=0;
			}
			dfn[i][i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			dfn[u][v]=cnt[u][v]=1;
			dfn[v][u]=cnt[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dfn[i][j]=min(dfn[i][j],dfn[i][k]+dfn[k][j]);
				}
			}
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
