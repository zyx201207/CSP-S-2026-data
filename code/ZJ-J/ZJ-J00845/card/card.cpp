#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],f[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int p=0;
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[++p]=a[i];
		for(int i=1;i<=p;i++)
		{
			int flag=0;
			if(f[i]==f[p])
			{
				flag=1;
				pos=i;
			}
		}
		if(flag)
		{
			for(int i=pos;i<=p;i++)
			{
				f[i]=0;
			}
			p=pos;
		}
	}
	return 0;
}

           