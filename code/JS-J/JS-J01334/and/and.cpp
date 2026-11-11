#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m;
int a[N];
long long ans = -1e9;
int maxx = -1e9;
void dfs(int x,long long num,int nu)//x:dang qian xia biao;num:dang qian an wei yu zhi he;nu:dang qian zong gong xuan de shu liang
{
	if(nu == m && num > ans)
	{
		ans = num;
		return ;
	}
	else if(nu == m)
	{
		return ;
	}
	else if((n - x) < (m - nu))//n - x:sheng yu shu zi shu liang
	{
		return ;
	}
	for(int i = x + 1;i <= n;i ++)
	{
		dfs(i,num & a[i],nu + 1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if(m == 1)
	{
		cout << maxx;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 1;i <= n;i ++)
	{
		dfs(i,1LL * a[i],1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
