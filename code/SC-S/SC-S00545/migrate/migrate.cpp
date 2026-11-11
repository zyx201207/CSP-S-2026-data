#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+3;
int c,t,n,pre[N],nxt[N],len[N];
ll d,a[N],dp[N][2];
vector<int>g[N];
void init(){
	for(int i=1;i<=n;i++){
		g[i]=vector<int>();
		pre[i]=nxt[i]=len[i]=0,dp[i][0]=dp[i][1]=0;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++)	cin>>a[i];
		#define dis(u,v) (a[v]-a[u])
		for(int u=1,v=1;u<=n;u++){
			while(v<n&&dis(u,v+1)<=d)	v++;
			nxt[u]=v;
		}
		for(int v=n,u=n;v>=1;v--){
			while(u>1&&dis(u-1,v)<=d)	u--;
			pre[v]=u;
		}
		for(int u=n;u>=1;u--)	len[u]=len[nxt[u]]+1;
		#define check2(u,k,v) (dis(u,v)>d&&dis(u,k+1)<=d&&dis(k-1,v)>d&&(k+2>v||dis(u,k+2)>d))
		for(int u=1,k=1,v=1;u<=n;u++){
			while(k<n&&dis(u,k+1)<=d){
				k++;
				while(v<n&&dis(k,v+1)<=d)	v++;
				if(u!=k&&v!=k&&check2(u,k,v))	g[u].push_back(v);
			}
		}
		#define check1(u,k,v) (v==u+1||(dis(u,k)<=d&&dis(k,v)<=d&&dis(u,k+1)>d&&dis(k-1,v)>d))
//		for(int k=n;k>=1;k--){
////			while(u>1&&dis(u,k+1)<=d)	u--;
////			while(v>1&&dis(k-1,v)<=d)	v--;
//			
//			int u=pre[k],v=nxt[k];
//			cout<<u<<' '<<k<<' '<<v<<'\n';
//			if(check1(u,k,v))	dp[u]+=dp[v];
//		}
		for(int u=n;u>=1;u--){
			dp[u][0]=1;
			int k=nxt[u],v=nxt[k];
			if(check1(u,k,v))	dp[u][0]+=dp[k][0];
		}
		for(int u=n;u>=1;u--){
			for(int v:g[u])	dp[u][1]+=dp[v][0];
			int k=nxt[u],v=nxt[k];
			if(u==k-1)	dp[u][1]+=dp[k][1];
			else if(check1(u,k,v))	dp[u][1]+=dp[v][1];
		}
		ll ans=0;
		for(int u=1;u<=n;u++)	ans+=dp[u][1];
		cout<<ans<<'\n';
	}
	return 0;
}/*
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+3;
int c,t,n,pre[N],nxt[N],len[N];
ll d,a[N],dp[N][2],dp2[N];
vector<int>g[N];
void init(){
	for(int i=1;i<=n;i++){
		g[i]=vector<int>();
		pre[i]=nxt[i]=len[i]=0,dp[i][0]=dp[i][1]=dp2[i]=0;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++)	cin>>a[i];
		#define dis(u,v) (a[v]-a[u])
		for(int u=1,v=1;u<=n;u++){
			while(v<n&&dis(u,v+1)<=d)	v++;
			nxt[u]=v;
		}
		for(int v=n,u=n;v>=1;v--){
			while(u>1&&dis(u-1,v)<=d)	u--;
			pre[v]=u;
		}
		for(int u=n;u>=1;u--)	len[u]=len[nxt[u]]+1;
		#define check2(u,k,v) (dis(u,v)>d&&dis(u,k+1)<=d&&dis(k-1,v)>d&&(k+2>v||dis(u,k+2)>d))
		for(int u=1,k=1,v=1;u<=n;u++){
			while(k<n&&dis(u,k+1)<=d){
				k++;
				while(v<n&&dis(k,v+1)<=d)	v++;
				if(u!=k&&v!=k&&check2(u,k,v))	g[u].push_back(v);
			}
		}
		#define check1(u,k,v) (v==u+1||(dis(u,k)<=d&&dis(k,v)<=d&&dis(u,k+1)>d&&dis(k-1,v)>d))
//		for(int k=n;k>=1;k--){
////			while(u>1&&dis(u,k+1)<=d)	u--;
////			while(v>1&&dis(k-1,v)<=d)	v--;
//			
//			int u=pre[k],v=nxt[k];
//			cout<<u<<' '<<k<<' '<<v<<'\n';
//			if(check1(u,k,v))	dp[u]+=dp[v];
//		}
		for(int u=n;u>=1;u--){
			dp[u][0]=1;
			int k=nxt[u],v=nxt[k];
			if(check1(u,k,v))	dp[u][0]+=dp[k][0];
		}
		for(int u=n;u>=1;u--){
			for(int v:g[u])	dp2[u]+=dp[v][0];
			int k=nxt[u],v=nxt[k];
			if(u==k-1)	dp[u][1]+=dp2[k]+dp[k][1];
			else if(check1(u,k,v))	dp[u][1]+=dp2[v]+dp[v][1];
		}
		ll ans=0;
		for(int u=1;u<=n;u++)	ans+=dp[u][1]+dp2[u];
		cout<<ans<<'\n';
	}
	return 0;
}
*/