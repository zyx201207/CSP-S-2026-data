#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=510,MAXM=2e4+10;

ll c,n,m,d,q,w[MAXM],a[MAXN][MAXM],t[MAXN][MAXM];
ll t1[3][MAXM],a2[3][MAXM],id3[MAXM];
bool id2[3][MAXM];
int st,ed;
ll ans=0;
struct Node{ll u,s;};
vector<Node> mp[MAXM];
bool vis[MAXM];
namespace yixing{
	inline void dfs(int u,int last,ll res){
	//	cout<<u<<" "<<last<<" "<<res<<"\n";
		if (u==ed){
			ans=min(ans,t[last][u]+res);
			return;
		}
		for (Node tt:mp[u]){
			int v=tt.u,s=tt.s;
			if (vis[v])continue;
			vis[v]=1;
		//	cout<<u<<" "<<v<<" "<<last<<" "<<s<<" "<<t[last][u]<<" "<<t[s][u]<<"\n";
			if (s==last)dfs(v,last,res);
			else dfs(v,s,res+t[last][u]+t[s][u]);
			vis[v]=0;
		}
	}
	inline void baoli(){
		for (int i=1;i<=n;i++){// xianlu
			int k;cin>>k;
			cin>>a[i][1]>>t[i][a[i][1]];
			for (int j=2;j<=k;j++){
				cin>>a[i][j]>>t[i][a[i][j]];
				mp[a[i][j-1]].push_back({a[i][j],i});
				mp[a[i][j]].push_back({a[i][j-1],i});
			}
		}
		//	for (int i=1;i<=m;i++){cout<<i<<" :";for (Node v:mp[i])cout<<v.u<<" ";cout<<"\n";}
		while (q--){
			cin>>st>>ed;
			memset(vis,0,sizeof(vis));
			ans=1e18+10,vis[st]=1;
			dfs(st,0,0);
			cout<<ans+w[st]+w[ed]<<"\n";
		}
	}
	inline void le2(){
		for (int i=1;i<=n;i++){
			int k;cin>>k;
			for (int j=1;j<=k;j++){
				cin>>a2[i][j]>>t1[i][a2[i][j]];
				id2[i][a2[i][j]]=1;
				id3[a2[i][j]]=i;
			}
		}
		while (q--){
			cin>>st>>ed;
		//	cout<<id3[st]<<" "<<id3[ed]<<"\n";
			if ((id2[1][st]&&id2[1][ed])||(id2[2][st]&&id2[2][ed])){
			//	cout<<"123123123\n";
				ll ans=1e18;
				if (id2[1][st]&&id2[1][ed])ans=min(ans,w[st]+w[ed]+t1[1][st]+t1[1][ed]);
				if (id2[2][st]&&id2[2][ed])ans=min(ans,w[st]+w[ed]+t1[2][st]+t1[2][ed]);
				cout<<ans<<"\n";
			}else {
				ll ans=1e18;
				for (int u=1;u<=m;u++)if (id2[1][u]&&id2[2][u]){ans=min(ans,w[st]+w[ed]+t1[id3[st]][st]+t1[id3[st]][u]+t1[id3[ed]][u]+t1[id3[ed]][ed]);
				//	cout<<u<<"qqqwwww  :"<<w[st]+w[ed]+t1[id3[st]][st]+t1[id3[st]][u]+t1[id3[ed]][u]+t1[id3[ed]][ed]<<"\n";
				}
				cout<<ans<<"\n";
			}
		}
	}
	inline void Main(){
		cin>>c>>n>>m>>d>>q;
		for (int i=1;i<=m;i++)cin>>w[i];
		if (n<=2)le2();
		else baoli();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	yixing::Main();
	return 0;
}