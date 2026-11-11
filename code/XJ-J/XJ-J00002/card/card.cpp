#include<bits/stdc++.h>
using namespace std;
long long n,m,l,a[500005],t[500005],mn[500005];
bool tv[500005];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(tv[a[j]])
			{
				for(;mn[l]!=a[j];l--)
				{
					tv[mn[l]]=0;
					mn[l]=0;
				}
			}
			else
			{
				tv[a[j]]=1;
				mn[++l]=a[j];
			}
		}
		for(long long j=1;j<=l;j++)
		{
			t[mn[j]]++;
			tv[mn[j]]=0;
			mn[j]=0;
		}
		l=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	//10 3 3 1 2 1 3 2 3 1 2 1
	return 0;
} 
