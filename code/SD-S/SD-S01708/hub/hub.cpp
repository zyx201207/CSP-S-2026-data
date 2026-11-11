/*
选k座城市
不超过两个连通块 并查集
di这座城市到任意城市的最小距离
通勤半径 这其中的最大值 

*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <int> e[N];
int ch[N];//选择的点 
int f[N];//是否选过 
int cnt_bcj=0;
int vis[N];//是否连通 
int vis2[N];//求最短距离
int dp[N];//到每个点的距离 
int ans_tmp=0x3f3f3f3f;
int n,k;
int ans=0x3f3f3f3f;
void dfs2(int u){
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(vis2[v]==0){
			vis2[v]=1;
			if(dp[v]==0) dp[v]=dp[u]+1;
			else dp[v]=min(dp[v],dp[u]+1);
			dfs2(v);
		}
	}
}
void dfs(int u){
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		for(int j=1;j<=k;++j){
			if(v==ch[j]) {
				vis[v]=1;
				dfs(v);
				break;
			}
		}
	}
	return ;
}
void chose(int cnt){
	if(cnt==k+1){
		int ltc=0;
		for(int i=1;i<=k;++i){
			if(vis[ch[i]]){
				ltc++;
				dfs(ch[i]);
			}
		}
		if(ltc>2) return ;
		//最小距离
		for(int i=1;i<=k;++i){
			memset(vis2,0,sizeof(vis2));
			vis2[ch[i]]=1;
			dfs2(ch[i]);
			for(int j=1;j<=n;++j){
				ans_tmp=max(ans_tmp,dp[ch[j]]);
				dp[ch[j]]=0;
			}
		} 
		
		ans=min(ans_tmp,ans);
		return ;
	}
	//搜索选择 
	for(int i=1;i<=n;++i){
		if(f[i]==0){
			ch[cnt]=i;
			f[i]=1;
			chose(cnt+1);
			f[i]=0;
		}	
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		
		memset(f,0,sizeof(f));
		ans=0x3f3f3f3f;
		ans_tmp=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u); 
		}
		chose(1);
		cout<<ans<<endl;
		for(int i=1;i<=n;++i){
			e[i].clear();
		}
	}
}
