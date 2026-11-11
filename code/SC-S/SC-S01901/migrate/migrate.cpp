#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long c,t,n,d,a[200010],vis[5010],vis2[5010],cnt[5010],ans,Cnt;
vector<long long>g[200010];
void dfs(long long x,long long step){
	if(step==vis[x]-1){
		++cnt[x];
//		return;
//		cout<<x<<" ";
	}
	for(long long v:g[x]){
		if(!vis2[v]){
			vis2[v]=1;
			dfs(v,step+1);
			vis2[v]=0;
		}
	}
}
signed main(){
	ios
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				} 
			}
		}
		for(long long i=1;i<=n;++i){
			memset(vis,0,sizeof vis);
			memset(vis2,0,sizeof vis2);
			memset(cnt,0,sizeof cnt);
			queue<long long>q;
			q.push(i);
			vis[i]=1;
			while(!q.empty()){
				long long x=q.front();
				q.pop();
				for(long long v:g[x]){
					if(!vis[v]){
						vis[v]=vis[x]+1;
						q.push(v);
					}
				}
			}
			vis2[i]=1;
//			cout<<i<<":\n";
			dfs(i,0);
//			for(long long i=1;i<=n;i++)cout<<cnt[i]<<" ";
//			cout<<"\n";
			for(long long i=1;i<=n;i++)ans+=(cnt[i]==2);
		}
		cout<<ans/2<<"\n";
		for(long long i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}
