#include <bits/stdc++.h>
using namespace std;
int n,m;
int In[300003];
int num[300003];
int input[300003];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> input[i];
	}
	for (int k = 1;k <= n;k++)
	{
		int p = 0,cnt = 0;
		for (int i = k;i <= n;i++)
		{
			p = input[i];
			cnt++;
			In[cnt] = p;
			for(int j = 0;j < cnt;j++)
			{
				if(In[j] == p)
				{
					cnt = j;
				}
			}
		}
		for (int j = 1;j <= cnt;j++)
		{
			num[In[j]]++;
		}
}
	for (int i = 1;i <= m;i++)
		cout << num[i] << " ";
	return 0;
}