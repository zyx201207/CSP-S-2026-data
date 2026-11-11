#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using lnt=long long;
/*====================*/
const int N=510;
int op,n,m,d,q,k,u,t,uu,tt,ans,w[N],v[N][N];
bool vis[N];
/*====================*/
void dfs(int x,int ed,int sum){
	if(x==ed){
		ans=min(ans,sum);
		return;
	}
	vis[x]=true;
	for(int i=1;i<=n;i++){
		if(v[x][i]!=0&&!vis[i]) dfs(i,ed,sum+v[x][i]);
	}
}
int main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	/*====================*/
	cin>>op>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int i=1;i<=k/2;i++) cin>>u>>t>>uu>>tt;
		v[u][uu]=t+tt;
		cin>>uu>>tt;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		memset(vis,false,sizeof(vis));
		cin>>u>>t;
		dfs(u,t,0);
		cout<<ans<<endl;
	}
	system("fc subway.out subway4.ans");
	return 0; 
}
