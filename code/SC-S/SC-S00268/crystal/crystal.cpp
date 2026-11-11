#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
long long a[N],b[N];
int n,m,ans=1,sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				b[j]=0;
			}
			else if(a[i]>=a[j])
			{
				b[j]=a[i]-a[j];
			}
			else
			{
				b[j]=a[j]-a[i];	
			}
		}	
		sort(b+1,b+n+1);
		for(int j=1;j<=n;j++)
		{
			if((m-b[j])>0||(m-b[j])==0)
			{
				sum++;
				m=m-b[j];
			}
			else
			{
			    break;	
			}
		}
		ans=max(ans,sum);
	} 
	cout<<ans;
	return 0;
}
