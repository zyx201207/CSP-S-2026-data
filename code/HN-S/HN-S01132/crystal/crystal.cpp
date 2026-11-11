#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[500100],y;
int ans=0;
void num(int x)
{
	ans++;
	int sum;
	sum=a[x+1]-a[x];
	m=m-ans*sum;
	if(m>=0)
	{
		b[y]++;
		num(x+1);
	}
	ans--;
}
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
		int y=0;
		for(int j=1;j<n;j++)
		{
			int x;
			if(a[j]>a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
			if(a[i-1]<a[j]) y++;
		}
		if(y==n-1) break;
	}
	for(int i=1;i<n;i++){
		y=i;
		num(i);
	}
	int maxx=1;
	for(int i=1;i<n;i++)
	{
		if(b[i]>maxx) maxx=b[i];
	}
	cout<<maxx+1;
	return 0;
} 
