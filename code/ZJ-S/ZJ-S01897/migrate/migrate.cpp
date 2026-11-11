#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=10010;

int C,T;
int n,d;
int x[N];
int ans=0;
int milen[N][N];
int F=0;
vector<int> g[N];

void dfs(int u,int i,int v,int f=0,int len=0){
	if(i==v){
		if(len>milen[u][v]) return ;
		if(len==milen[u][v]) F=1;
		if(len<milen[u][v]) milen[u][v]=len,F=0;
		return ;
	}
	if(len>=milen[u][v]) return ;
	if(len>=milen[u][i]) return ;
	milen[u][i]=len;
	for(auto nxt:g[u]){
		if(nxt==f) continue;
		dfs(u,nxt,v,i,len+abs(x[i]-x[nxt]));
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>C>>T;
	while(T--){
		memset(milen,0x3f,sizeof milen);
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(abs(x[i]-x[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				F=0;
				dfs(i,i,j);
				if(F) ans++;
			}	
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
