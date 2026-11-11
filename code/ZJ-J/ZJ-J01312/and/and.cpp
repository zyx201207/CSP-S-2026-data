#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
long long k[200005];
bool f[200005];
void dfs(long long t){
	if(t==m+1){
		long long sum=k[1];
		for(int i=2;i<=m;i++)sum=(sum&k[i]);
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++)
		if(!f[i]){
			f[i]=1;
			k[t]=a[i];
			dfs(t+1);
			f[i]=0;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}