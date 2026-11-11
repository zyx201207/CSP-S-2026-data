#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int a[200010];
int f[200010];
void dfs(int k,int l,int sum){
	if(l==0){ans=max(ans,sum);return;}
	for(int i=k;i<=n-l+1;i++){dfs(i+1,l-1,sum&a[i]);}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		m=0;
		for(int i=1;i<=n;i++){int kk;cin>>kk;m=max(kk,m);}
		cout<<m;return 0;
	}
	if(m==2&&n<=5000){
		for(int i=1;i<=n;i++)cin>>a[i];
		m=0;
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)m=max(m,a[i]&a[j]);
		cout<<m;return 0;
	}
	if(m==n){
		m=2147483647;
		for(int i=1;i<=n;i++){int t;cin>>t;m&=t;}
		cout<<m;return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,m,2147483647);
	cout<<ans;
	return 0;
}