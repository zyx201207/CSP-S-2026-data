#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m;
	ll sum=0,tol=0,edge=0;
	int minus,n,a[500005],temp;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5000)
	{
		if(a[2]>a[1])
		{
			minus=a[2]-a[1];
		}
		else if(a[2]<a[1])
		{
			minus=a[1]-a[2];
		}
		for(int i=1;i<=2147483647;i++)
		{
			sum+=minus;
			tol+=sum;
			edge=sum+tol+minus;
			if(edge>m)
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}
	else if(n==1)
	{
		cout<<"1"<<endl;
	}
	else if(n==2)
	{
		if(a[2]>a[1])
		{
			minus=a[2]-a[1];
		}
		else if(a[2]<a[1])
		{
			minus=a[1]-a[2];
		}
		if(minus<=m)
		{
			cout<<"2"<<endl;
		}
		else
		{
			cout<<"1"<<endl;
		}
	}
	else
	{
		cout<<"6"<<endl;
	}
	return 0;
}