#include<bits/stdc++.h>
using namespace std;

int n , m;
long long ans=0;
int a[200050] , vis[200050];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int deep , int now_ans)
{
	if(deep==m+1)
	{
		ans=now_ans;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if((now_ans&a[i])<=ans) continue;
		vis[i]=1;
		dfs(deep+1,now_ans&a[i]);
		vis[i]=0;
	}
	return ;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,INT_MAX);
	cout << ans;
	
	return 0; 
}
