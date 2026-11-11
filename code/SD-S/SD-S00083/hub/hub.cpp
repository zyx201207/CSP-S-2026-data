#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,t,n,k,ans,dp[maxn],now,fat[maxn],ffa[maxn];
bool vis[maxn];
vector<int> ma[maxn];
void yu(int x,int fa){
	fat[x]=fa;
	for(int u:ma[x]){
		if(u==fa)continue;
		yu(u,x);
	}
}
void check(int x,int fa){
	if(vis[x])dp[x]=0;
	for(int u:ma[x]){
		if(u==fa)continue;
		check(u,x);
		dp[x]=min(dp[x],dp[u]+1);
	}
}
void check1(int x,int fa){
	for(int u:ma[x]){
		if(u==fa)continue;
		dp[u]=min(dp[u],dp[x]+1);
		check1(u,x);
	}
}
int fin(int x){
	if(ffa[x]==x)return x;
	return ffa[x]=fin(ffa[x]);
}
void dfs(int step){
	if(step==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=vis[i];
		}
		if(cnt!=k)return ;
		for(int i=1;i<=n;i++){
			ffa[i]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(vis[i]==1&&vis[j]==1){
					if(fat[i]==j||fat[j]==i){
						int l1=fin(i),l2=fin(j);
						if(l1==l2)continue;
						ffa[l1]=l2;
					}
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(fin(i)==i&&vis[i]==1)cnt++;
		}
		if(cnt>2)return ;
		for(int i=1;i<=n;i++){
			dp[i]=n;
		}
		now=0;
		check(1,0);
		check1(1,0);
		for(int i=1;i<=n;i++){
			now=max(now,dp[i]);
		}
		ans=min(ans,now);	
		return ;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=n;
		for(int i=1;i<=n;i++){
			ma[i].clear();
			vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ma[u].push_back(v);
			ma[v].push_back(u);
		}
		if(n<=20){
			yu(1,0);
			dfs(1);
			cout<<ans<<'\n';
		}
		else{
			n=(n+1)/2+1;
			if(k==n){
				cout<<0<<'\n';
				continue;
			}
			else if(k>=n-2){
				cout<<1<<'\n';
				continue;
			}
			if(k==1){
				cout<<n/2<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++){
				if((n/2-i)-(1+i)+1+(n-i)-(n/2+1+i)+1<=k){
					cout<<i<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}

