#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1,common_left;
long long a[100005];
map<long long,long long>vis;
bool tr[100005];
void dfs(long long u,long long cost){
	memset(tr,false,sizeof tr);
	for(long long i=1;i<=n;i++){
		if(tr[i])continue;
		for(long long j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i]==a[j]){
				tr[j]=true;
				vis[a[i]]++;
			}
		}
	}
	for(auto out:vis){
		maxn=max(out.second+1,maxn);
	}
	vis.clear();
	if(u==n+1)return ;
	for(long long i=0;i<=m-cost;i++){
		a[u]+=i;
		dfs(u+1,cost+i);
		a[u]-=i;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		common_left=a[i]-a[i-1];
	}
	if(n<=10&&m<=15){
		dfs(1,0);
		cout<<maxn;
	}else{
		long long ans=1;
		for(long long i=n-1;i>=1;i--){
			if(m-common_left*(n-i)>=0){
				m-=common_left*(n-i);
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}