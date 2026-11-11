#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int maxn=2e5+10;
ll a[maxn];
ll ans=-1e9;
bool vis[maxn];
void dfs(ll step,ll sum,ll cnt){
	if(cnt==m){
		ans=max(sum,ans);
		//cout<<ans<<endl;
		return ;
	}
	if(step==n){
		return ;
	}
	dfs(step+1,sum&a[step],cnt+1);
	dfs(step+1,sum,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,pow(2,20)-1,0);
	cout<<ans;
	return 0;
}
