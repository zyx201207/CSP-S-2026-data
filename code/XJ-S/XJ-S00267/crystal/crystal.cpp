#include<bits/stdc++.h> 
using namespace std;
int i,j,n,m,a[10000005],b[10000005],minn=INT_MAX,sum=1,f[10000005];
struct node
{
	int x,n;
}c[100000005];
bool cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(i=1;i<n;i++)
	{
		c[i].x=b[i];
	}
	sort(c+1,c+1+n,cmp);
	for(i=1;i<=n;i++)
	{
	if(b[i]>m)
	continue;
	else
	{
		if(b[i]==0)
		{
		sum++;
		continue;
	}
	else
	{
		m-=abs(b[i]);
		sum++;
		f[i]=0;
		if(f[i-1]==0)
		{
			m-=b[i]*sum;
		}
	}
	}
	}
	cout<<sum;
	return 0;
}
