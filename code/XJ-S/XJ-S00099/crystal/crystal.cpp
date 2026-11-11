#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxx=5e5+5;
long long a[maxx],sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	long long cha=a[n]-a[n-1];
	for(int i=1;i<=n;i++)
	{
		sum+=cha*i;
		if(sum==m) 
		{
			cout<<i+1;
			return 0;
		}
		else if(sum>m)
		{
			cout<<i;
			return 0;
		}
	}
	

	return 0;
}

