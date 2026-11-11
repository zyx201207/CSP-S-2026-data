#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int s(int x,int y)
{
	int sum=0,t=0;
	int z=min(x,y);
	while(z!=0)
	{
		if(x%2==1&&y%2==1)
		{
			int q=0;
			if(t>0)
			{
				q=1;
				for(int i=1;i<=t;i++)
				{
					q*=2;
				}
			}
			sum+=q;
		}
		x/=2;
		y/=2;
		z=min(x,y);
		t++;
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i+m<=n;i++)
	{
		int ans=0;
		for(int j=i;j<=i+m-1;j+=2)
		{
			ans+=s(a[j],a[j+1]);
		}
		if(ans>num) num=ans;
	}
	cout<<num;
	return 0;
}
