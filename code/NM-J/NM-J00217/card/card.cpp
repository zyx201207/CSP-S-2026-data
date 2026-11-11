#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int s[500005],t = 0;
int flag[500005],g[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(flag[a[j]])
			{
				for(int l = flag[a[j]];l <= t;l++)
				{
					flag[s[l]] = 0;
				}
				t = flag[a[j]];
			}
			s[++t] = a[j];
			flag[a[j]] = t;
		}
		while(t != 0)
		{
			flag[t] = 0;
			g[s[t]]++;
			t--;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		if(g[i] > 1) cout << g[i]-1 << " ";
		else cout << g[i] << " ";
	}
    return 0;
}
