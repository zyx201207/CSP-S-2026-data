#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=11;
const int INF=1e9+10;

int c,t,n,k,vis[MAXN],cnt,minn=INF;
vector<int> mp[MAXN];
namespace yixing{
	inline void check(int u,int fa){
		for (int v:mp[u]){
			if (v==fa)continue;
			if (vis[v]&&(!vis[u]))cnt++;
			check(v,u);
		}
	}
	inline void sfind(int u,int fa,int res){
		if (vis[u])return minn=min(minn,res),void();
		for (int v:mp[u]){
			if (v==fa)continue;
			sfind(v,u,res+1);
		}
	}
	inline void Main(){
		cin>>n>>k;
		for (int i=1;i<=n;i++)mp[i].clear();
		for (int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			mp[u].push_back(v),mp[v].push_back(u);
		}
		int ans=INF;
		for (int mask=0;mask<=((1<<n)-1);mask++){
			int kk=0;
			for (int u=1;u<=n;u++)if (mask&(1<<(u-1)))vis[u]=1,kk++;
			if (kk!=k)continue;
			cnt=0;check(1,0);
			if (cnt>2)continue;
		//	cout<<"kk:"<<cnt<<" "<<kk<<"\n";
			for (int i=1;i<=n;i++)if (vis[i])cout<<i<<" ";
		//	cout<<"\n";
			int maxn=-INF;
			for (int u=1;u<=n;u++){
				if (vis[u])continue;
				minn=INF;
				sfind(u,0,0);
				maxn=max(maxn,minn);
			}
			memset(vis,0,sizeof(vis));
			ans=min(ans,maxn);
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while (t--)yixing::Main();
	return 0;
}