#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
bool vis[100005];
long long ans=0;
long long h=pow(2,30);
void dfs(long long k){
	if(k>m){
		ans=max(ans,h);
		h=pow(2,30);
		
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]){
			vis[i]=1;
			h=h&&a[i];
			dfs(k+1);
			vis[i]=0;
		}
		
	}	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
	}
	cout<<ans;
	return 0;
}
