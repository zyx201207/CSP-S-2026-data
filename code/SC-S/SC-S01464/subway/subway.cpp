#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int c,n,m,d,q,k,a,t,x,y,w[500010],dist[500010],len[510][510],res; // len[i][j] 表示从第 i 个车到地 j 个的最小
vector<pair<int,int> >adj[500510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			adj[m+i].push_back({a,t});
			adj[a].push_back({m+i,t});
		}
	}
	memset(len,0x3f,sizeof(len));
	for(int i=1;i<=n;i++) len[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto u:adj[i]){
			for(auto v:adj[i]){
				if(u==v) continue;
				len[u.first-m][v.first-m]=len[v.first-m][u.first-m]=min(len[u.first-m][v.first-m],u.second+v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				len[j][i]=len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		res=INF;
		for(auto u:adj[x]){
			for(auto v:adj[y]){
				res=min(res,u.second+len[u.first-m][v.first-m]+v.second);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
	return !"I'm xcb";
}
/*
d 肯定有用，不然给你干嘛
离线？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？


NOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
hao nan aaaaaaaaaaaaaaaaaaaaaaa
if I don't get 1=, I will AFO!!!
I don't want to shang whk!



100+32


难我天？？？？？？

复杂度：md^2+n^3+qd^2
d=20,m=5e5,q=1e5,n=500
也就是大概 3e8

if ping ce ji is fast, I can get 100!!!
*/