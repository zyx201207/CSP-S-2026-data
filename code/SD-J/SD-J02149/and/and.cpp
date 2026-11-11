#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll a[200005],n,m,ans,vis[200005];
void dfs(ll k,ll c){
	if(k==m){
		ans=max(ans,c);
		return ;
	}
	for(int i=n-k;i>=1;i--){
		vis[i]=1;
		dfs(k+1,c&a[i]);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll t=a[n],cnt=0;
	while(t){
		cnt<<=1;
		cnt++;
		t>>=1;
	}
	dfs(0,cnt);
	ll ans1=a[n];
	for(int i=n-m+1;i<n;i++){
		ans1&=a[i];
	}
	cout<<max(ans,ans1);
	return 0;
}
//RP+=INF
