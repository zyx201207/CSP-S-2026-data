#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10,M=3e5+10;
int n,m,num[M],a[N],s[N];
bool mu[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	 } 
	for(int i=1;i<=n;i++)
	{
		memset(s,0,sizeof s);
		memset(mu,0,sizeof mu);
		int p=0;
		for (int j=i;j<=n;j++)
		{
			int l=a[j];
			if (!mu[l])
			{
				p++;
				s[p]=l;
				mu[l]=1;
			}
			else
			{
				while(true)
				{
					if (s[p]==l)
					{
						break;
					}
					mu[s[p]]=0;
					s[p]=0;
					p--;
				}
			}
		}
		for (int i=1;i<=p;i++)
		{
			num[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << num[i] << " "; 
	}
	return 0;
}
