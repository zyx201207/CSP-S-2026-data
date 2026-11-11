#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500010],l,r,ans=0,s=0,d=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(unsigned long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long int i=a[1];i<=a[n]+m;i++)
	{
		d=0;
		s=0;
		l=1;
		for(long long int j=1;j<=n;j++)
		{
			if(a[j]>i)
			{
				break;
			}
			s+=i-a[j];
			if(s>m)
			{
				s-=a[l];
				if(s<=m)
				{
					l++;
					d--; 
				}
				else
				{
					break;
				}
			}
			d++;
		}
		ans=max(ans,d);
	}
	cout<<ans;
	return 0;
}
/*
 5 8
-3 -1 2 2 7
*/
