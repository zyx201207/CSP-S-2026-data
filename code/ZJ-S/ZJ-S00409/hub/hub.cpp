#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
vector<pair<int,int>>rd;
vector<int>to[N];
int n,k;
int vis[N];
int dp[N][3];
int fs[N],sc[N];
void gtd(int x,int fa){
	vis[x]=1;
	fs[x]=sc[x]=0;
	for(auto &g:to[x]){
		if(g==fa)continue;
		gtd(g,x);
		int gt=fs[g]+1;
		if(gt>fs[x]){
			sc[x]=fs[x];
			fs[x]=gt;
		}else{
			sc[x]=max(sc[x],gt);
		}
	}
}
void dfs(int x,int fa,int lst,int mk){
	dp[x][1]=1;
	int cnt=0;
	for(auto &g:to[x]){
		if(g==fa)continue;
		if(fs[g]+1==fs[x]){
			dfs(g,x,max(lst,sc[x])+1,mk);
		}else{
			dfs(g,x,max(lst,fs[x])+1,mk);
		}
		dp[x][1]+=min(dp[g][1],dp[g][0]);
		if(dp[g][0]==2e9)cnt++;
	}
	//cout<<mk<<" "<<fs[x]<<"\n";
	if(fs[x]>mk)dp[x][0]=2e9;
	else dp[x][0]=0;
	if(lst>mk||cnt>1)dp[x][2]=2e9;
	else {
		if(cnt){
			for(auto &g:to[x]){
				if(g==fa)continue;
				if(dp[g][0]==2e9)dp[x][2]=min(dp[g][2],dp[g][1]);
			}
		}
		else{
			dp[x][2]=2e9;
			for(auto &g:to[x]){
				if(g==fa)continue;
				dp[x][2]=min(dp[x][2],min(dp[g][2],dp[g][1]));
			}
		}
	}
}
bool check(int x){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			gtd(i,0);
			dfs(i,0,0,x);
			//cout<<i<<" "<<x<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
			ans+=max(1ll,min(dp[i][1],dp[i][2]));
		}
	}
	//cout<<x<<" "<<ans<<"\n";
	return ans<=k;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		rd.clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			rd.push_back({u,v});
		}
		int mn=2e9;
		for(auto &g:rd){
			for(int i=1;i<=n;i++)to[i].clear();
			for(auto &h:rd){
				if(g==h)continue;
				to[h.first].push_back(h.second);
				to[h.second].push_back(h.first);
			}
			int l=0,r=n;
			while(r-l>1){
				int mid=(l+r)/2;
				if(check(mid)){
					r=mid;
				}else{
					l=mid;
				}
			}
			mn=min(mn,r);
		}
		cout<<mn<<"\n";
	}
	return 0;
}