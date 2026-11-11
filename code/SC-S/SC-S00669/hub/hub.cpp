#include<bits/stdc++.h>
#define ll long long
#define VI vector<int>
#define endl '\n'
#define up(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
int c,t,n,k,leaf[105],tot;
VI G[105];
int dep[105],up[105][21],dis[100005];
void dfs(int id,int fa){
	dep[id]=dep[fa]+1;
	up[id][0]=fa;
	up(i,1,20) up[id][i]=up[up[id][i-1]][i-1];
	for(int to:G[id]) dfs(to,id);
}
bool cmp(int x,int y) {
	return x>y;
}
int LCA(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=20;i>=0;i--)
		if(dep[up[a][i]]>=dep[b]) a=up[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
		if(up[a][i]!=up[b][i])
			a=up[a][i],b=up[b][i];
	return up[a][0];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		up(i,1,n-1){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
		}
		dfs(1,0);
		up(i,1,n) up(j,i+1,n){
//			cout<<i<<" "<<j<<" "<<LCA(i,j)<<endl;
			dis[++tot]=dep[j]+dep[i]-2*dep[LCA(i,j)];
		}
//		up(i,1,tot) cout<<dis[i]<<" ";
//		cout<<endl;
		sort(dis+1,dis+1+tot,cmp);
		cout<<dis[k+1]<<endl;
	}
	return 0;
}
