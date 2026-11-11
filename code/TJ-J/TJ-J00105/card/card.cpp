#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int n,m,a[N],cnt[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[i]=0;
	}
	bool flag=false;
	int num=n;
	for (int i = 1; i <= n;i++)
	{
		num=n;
		for(int j=i; j <= num;j++)
		{
			cnt[a[j]]++;
			for(int k=j+1; k <= n;k++)
			{
				if (a[j]==a[k])
				{
					flag=true;
				}
				if (flag == true)
				{
					num--;
				}
			}              
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
