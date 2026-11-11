#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[1000000],vis[100000],s[100000];
ll dfs(ll ss,ll step){
	cout<<ss<<" "<<step<<"\n";
	vis[ss]=1;
	s[step]=ss;
	if(step==m){
		ll ans=s[1];
		for(int i=2;i<=m;i++){
			ans=ans&s[i];
		}
		return ans;
	}
	for(int i=1;i<=n;i++){
		if(vis[a[i]]==0){
			dfs(a[i],step+1);
			s[step]=0;
			vis[step]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n>=2e5){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxn=0;
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		memset(vis,0,sizeof(vis));
		maxn=max(maxn,dfs(a[i],1));
	}
	cout<<maxn<<"\n";
	return 0;
}

