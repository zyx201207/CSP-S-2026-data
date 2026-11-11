#include<bits/stdc++.h>
using namespace std;
long long n,m,t[300005],a[500005],cnt[300005],la,l;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int k=1;k<=n;k++)
	{
		memset(t,0,0x3f);
		for(int i=k;i<=n;i++)
		{
			t[a[i]]++;
			cnt[a[i]]++;
			if(t[a[i]]>=2)
			{
				int j=i-1;
				while(1)
				{
					if(t[a[j]])
					{
						t[a[j]]--;
						cnt[a[j]]--;
					}
					if(a[j]==a[i]) break;
					j--;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}

