#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,tot,m,ans=-1;
long long a[500050];
void solve(){
	for(int j=1;j<=n;j++){
		bool f=0;
		map<long long,vector<long long> > mp;
		int u=a[j];
		for(int k=63ll;k>=0ll;k--){
			if(u%(1<<j)==0){
				int x=u/(1ll<<j);
				//printf("1 ");
				if(mp[x].size()<j+1) mp[x].reserve(j+1);
				mp[x][j]++;
				int idx=j;
				while(mp[x][idx]==2){
					mp[x][idx]=0;
					if(idx+1>mp[x].size()) mp[x].reserve(mp[x].size()+1);
					mp[x][idx+1]++;
				}
			}			
		}for(auto x:mp){
			ans=max(ans,(int)x.second.size());
		}//printf("\n");
	}//exit(0);
}void dfs(int idx,int x){
	if(x==0){solve();return;}
	if(idx==n+1){solve();return;}
	for(int i=0;i<=x;i++){
		a[idx]+=i;
		dfs(idx+1,x-i);
		a[idx]-=i;
	}
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	dfs(1,m);
	printf("%lld",ans);
}
