#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005]={0};
long long ans=0,sum=0,v=0;
bool cms(long long o,long long p)
{
	return o>p;
}
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=2;i<=n;i++)
	{
		if(ans>=m)
		{
			break;
		}
		else if(a[i-1]<a[i])
		{
			a[i-1]+=1;
			ans++;
			if(i>2)
				i-=2;
			else if(i==2)
				i-=1;
		}
		else if(a[i-1]>a[i])
		{
			a[i]+=1;
			ans++;
		}
		else if(a[i-1]==a[i])
		{
			continue;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(long long j=2;j<=n;j++)
	{
		if(a[j-1]<a[j])
		{
			v++;
			b[v]=sum+1;
			sum=0;
		}
		else if(a[j-1]==a[j])
		{
			sum++;
		}
	}
	sort(b+1,b+1+v,cms);
	cout<<b[1];
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}