#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int m,n;
bool ans[64] = {false};
struct node
{
	int dec;
	bool bin[64];
}a[MX + 10];
void dfs(int nowcnt,int nownum,bool nowbin[])
{
	if(nownum > n)
	{
		return;
	}
	dfs(nowcnt,nownum + 1,nowbin);
	bool newbin[64];
	int i = 0;
	for(;i <= 32;i++)
	{
		if(nowbin[i] == 1 && a[nownum].bin[i] == 1)
		{
			newbin[i] = true;
		}
		else
		{
			newbin[i] = false;
		}
	}
	if(nowcnt >= m)
	{
		i = 0;
		while(ans[i] == newbin[i])
		{
			i++;
		}
		if(newbin[i] > ans[i])
		{
			for(i = 0;i <= 32;i++)
			{
				ans[i] = newbin[i];
			}
		}
		return;
	}
	else
	{
		dfs(nowcnt + 1,nownum + 1,newbin);
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ls,i = 1,j;
	cin >> n >> m;
	for(;i <= n;i++)
	{
		cin >> a[i].dec;
		ls = a[i].dec;
		j = 32;
		while(ls != 0)
		{
			a[i].bin[j] = ls % 2;
			j--;
			ls /= 2;
		}
	}
	for(int i = 0;i <= 32;i++)
	{
		a[0].bin[i] = true;
	}
	dfs(1,1,a[0].bin);
	i = 0;
	long long add = 1,finally = 0;
	for(j = 32;j >= 0;j--)
	{
		if(ans[j])
		{
			finally += add;
		}
		add *= 2;
		}
	cout << finally << '\n';
	return 0;
} 
