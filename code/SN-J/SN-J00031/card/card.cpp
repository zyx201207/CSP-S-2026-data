#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],js[300010];
bool t[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >>m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n<=8300)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<=n;j++)
			{
				int o = a[j];
				if(t[o]==0)
				{
					t[o]=1;
				}
				else
				{
					for(int k=j-1;k>=1;k--)
					{
						int p = a[k];
						t[p]=0;
						if(p==o)
						{
							break;
						}
					}
					t[o]=1;
				}
			}
			for(int j = 1;j<=m;j++)
			{
				js[j]+=t[j];
				t[j]=0;
			}
		}
		for(int i = 1;i<=m;i++)
		{
			cout << js[i] << ' ';
		}
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		if(a[i]!=a[i]+1)
		{
			int o = a[i];
			js[o]+=i;
		}
		for(int i = 1;i<=m;i++)
		{
			cout << js[i] << ' ';
		}
	}
	return 0;
}
