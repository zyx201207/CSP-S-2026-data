#include <bits/stdc++.h>
using namespace std;
const int M = 3e5+10;
const int N = 5e5+10;
int a[N];
int ans[M];
int siz = 0;
int bj[M] = {0},num[M] = {0};
int sss[M] = {0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	int w = 1;
	for (int i = 1;i <= n;i++)
	{
		siz = 0;
		memset(bj,0,sizeof bj);
		memset(num,0,sizeof num);
		memset(sss,0,sizeof sss);
		for (int j = i;j <= n;j++)
		{
			if (bj[a[j]] == 0)
			{
				sss[++siz] = a[j];
				num[a[j]] = siz;
				bj[a[j]] = 1;
			}
			else
			{
				for (int p = num[a[j]]+1;p <= siz;p++)
				{
					bj[sss[p]] = 0;
					num[sss[p]] = 0;
				}
				siz = num[a[j]];
			}
		}
		for (int j = 1;j <= siz;j++)
		{
			ans[sss[j]]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout <<ans[i] << ' ';
	}
	
	
	
	
	return 0;
} 
