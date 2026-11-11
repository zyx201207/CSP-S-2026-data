#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx;
void dfs(long long x,long long cnt,long long ans){
	cout<<x<<' '<<cnt<<' '<<ans<<'\n';
	if(n-x+1+cnt<m)return;
	if(cnt>=m){
		mx=max(mx,ans);
		return;
	}
	for(int i=x;i<=n;i++){
		//cout<<ans<<'&'<<a[i]<<'='<<(ans&a[i])<<'\n';
		//cout<<x<<' '<<cnt<<' '<<ans<<"->"<<i+1<<' '<<cnt+1<<(ans&a[i])<<'\n';
		dfs(i+1,cnt+1,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,(1<<31)-1);
	cout<<mx;
	return 0;
}
