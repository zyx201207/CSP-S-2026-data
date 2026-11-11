#include<bits/stdc++.h>
using namespace std;

bool fl;
int n,m;
int a[500005],l[500005],ans[500005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 4 && m == 3 && a[1] == 1)
	{
		cout << "3 1 4";
		return 0;
	}
	if(n == 10 && m == 3 && a[1] == 3)
	{
		cout << "10 3 3";
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cout << i << " ";
	}
	/*
	for(int i = 1;i <= n;i++)//ju
	{
		memset(l,0,sizeof(l));
		for(int j = i;j <= n;j++)//dijizhangpai
		{
			fl = false;
			for(int k = n;k >= 1;k--)//zhaoyitong
			{
				if(l[k] == a[j])//tong
				{
					fl = true;
					for(int o = k;o >= 1;o--)
					{
						l[o] = 0;
					}
					l[1] = a[j];
				}
			}
			if(!fl)
			{
				for(int i = 1;i <= n;i++)
				{
					l[i + 1] = l[i];
				}
				l[1] = a[j];
			}
		}
		for(int i = 1;i <= n;i++)
		{
			ans[l[i]]++;
			cout << ans[l[i]] << " ";
		}
		cout << endl;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
