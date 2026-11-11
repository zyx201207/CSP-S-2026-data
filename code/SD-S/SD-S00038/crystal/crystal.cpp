#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	int a[n+1],m1=m,a2[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		m1=m;
		a2[i]=1;
		for(int j=i-1;j>=1;j--)
		{
		    int c=a[i]-a[j];
		    if(c>m1)
		    {
		    	break;
			}
			m1-=c;
			a2[i]++;
		}
		if(a2[i]>max)
		{
			max=a2[i];
		}
	}
	cout<<max;
	return 0;
}
