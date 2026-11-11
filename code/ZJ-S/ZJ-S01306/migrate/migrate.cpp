#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace my{
	inline int read(){
		int c=getchar(),f=1,s=0;
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			s=s*10+(c^48);
			c=getchar();
		}
		return f*s;
	}
	int test_c;
	int n,m;
	int a[2000005];
	vector<signed>ve[2000005];
	int dis[2000005];
	int t[2000005];
	int dp[2000005];
	queue<int>q;
	int fa[2000005];
	int getf(int x){
		if(x==fa[x]) return x;
		fa[x]=getf(fa[x]);
		return fa[x];
	}
	void solvo1to6(){
		n=read();m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			fa[i]=i;
			t[i]=0;
		}
		for(int i=1;i<=n;i++){
			ve[i].clear();
			ve[i].shrink_to_fit();
			dis[i]=0x3f3f3f3f3f3f3f3f;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					ve[i].push_back(j);
					int u=getf(i),v=getf(j);
					if(u!=v){
						fa[v]=u;
					}
				}
			}
		}
		while(q.size())q.pop();
		for(int i=1;i<=n;i++){
			if(getf(i)==i){
				q.push(i);
				dis[i]=0;
				t[i]=1;
			}
		}
		
		while(q.size()){
			int u=q.front();
			q.pop();
			for(auto v:ve[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					t[v]=1;
					dp[v]=dp[u];
				}
				else if(dis[v]==dis[u]+1){
					if(dp[v]==0){
						dp[v]=1;
					}
					else{
						dp[v]=0;
					}
				}
			}
		}
		int ans=0;
		for(int i=2;i<=n;i++){
			ans+=dp[i];
		}
		printf("%lld\n",ans);
	}
	signed main(){
		test_c=read();
		int T=read();
		while(T--){
			if(test_c<=100) solvo1to6();
		}
		return 0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	return my::main();
}
