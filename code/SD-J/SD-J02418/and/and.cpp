#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
using namespace std;
const int N=2e5+10;
ll n,m;
ll a[N];
ll ans=-10;
void dfs(ll now,ll cnt,ll sum)
{
//	cout<<now<<" "<<cnt<<" "<<sum<<"\n";
	
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(now>n) return ;	
	dfs(now+1,cnt,sum);
	ll newsum=sum&a[now];
	if(cnt==0) newsum=a[now];
	dfs(now+1,++cnt,newsum);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	ll mx=-inf;
	ll tot;
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
		if(i==1) tot=a[1];
		else tot=tot&a[i];
		mx=max(mx,a[i]);		
	}
	//dfs(当前编号，计数，答案)
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		cout<<tot;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;                                            
} 
