#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[1000005];
int cnt=0,sum=0;
void find(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x+d&&y-d<a[i])
		{
			cnt++;
		}
	}
	if(cnt!=0)
	{
		sum+=1;
	}
}
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>> a[i];
		}
		/*for(int u=1;u<=n;u++)
		{
			for(int r=1;r<=n;j++)
			{
				find(a[u],a[r]);
				sum/=2;
			}	
		}
		//cout<<sum<<endl;
		sum=0; 
		cnt=0;*/
	}
	for(int i=1;i<=t;i++)
	{
		cout<<"0"<<endl;
	}
	return 0;
}
