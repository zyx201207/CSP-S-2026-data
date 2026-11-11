#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int n,m;
int a[N],ans[M];
struct node//shi fou bao han;
{
	int x;//x:wei zhi;
	bool b;//b:shi fou bao han
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		node flag[M] = {};
		int cur[2 * N] = {};
		int l = i,r = i;//dui lie de tou he wei
		for(int j = l;j <= n;j ++)
		{
			cur[++ r] = a[j];
			if(flag[a[j]].b)
			{
				for(int k = flag[a[j]].x;k <= r;k ++)
				{
					if(flag[cur[k]].b == 1 && flag[cur[k]].x > flag[a[j]].x)
					{
						flag[cur[k]].b = 0;
					}
				}
				r = flag[a[j]].x;
			}
			else
			{
				flag[a[j]].b = 1;
				flag[a[j]].x = r;
			}
		}
		for(int i = l + 1;i <= r;i ++)
		{
//			cout << cur[i] << " ";
			ans[cur[i]] ++;
		}
//		cout << endl;
	}
//	cout << endl;
	for(int i = 1;i <= m;i ++) cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
