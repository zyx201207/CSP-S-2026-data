#include<bits/stdc++.h>
using namespace std;
int a[200200];
int n,m;
int mx = 1;
int ans = -1;
void dfs(int st,int sum,int cnt)
{
	if (cnt  < ans )return ;
	if (ans == mx)
	{  
		cout<<ans;
		exit(0);
	}
	if (st > n + 1)return;
	if (sum > m)return ;
	if (sum == m)
	{
		ans = max(ans,cnt);
	}
	int u = cnt;
	u &= a[st];
	dfs(st + 1,sum + 1,u );
	
	dfs(st + 1,sum,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++)cin>>a[i],mx = max(mx,a[i]);
	
	
	if (m == 1)
	{
		
		cout<<mx;
		return 0;
	}
	if (m == n)
	{
		int ans = 0;
		ans = a[1];
		for (int i = 1;i <= n;i ++)ans &= a[i];
		cout<<ans;
		return 0;
	}
	dfs(1,0,1024 * 1024 * 1024 - 1);
	cout<<ans;
	return 0;
}