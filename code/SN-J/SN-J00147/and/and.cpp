#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[200010];
ll dfs(ll pos,ll step,ll val){
	if(val<=ans)return 0;
	if(step==m)return val;
	if(n-pos==m-step)return dfs(pos+1,step+1,(val&a[pos+1]));
	return max(dfs(pos+1,step,val),dfs(pos+1,step+1,(val&a[pos+1])));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());
	for(int i=1;i<=n-m;i++)ans=max(ans,dfs(i,1,a[i]));
	cout<<ans;
	return 0;
}

