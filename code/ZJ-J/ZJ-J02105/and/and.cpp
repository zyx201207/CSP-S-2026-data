#include <bits/stdc++.h>
using namespace std;
bool b[400000][35];
vector<bool> ap;
vector<int> a;
int n;
int goal;
vector<bool> location;
void running_ap()
{
	int need=0;
	for(int i=31;i>=0;i--)
	{
		need=0;
		for(int j=0;j<n;j++)
		{
			if(b[j][i]&&(!ap[j]))
			{
				need++;
			}
		}
		if(need>=goal)
		{
			location[i]=1;
			for(int j=0;j<n;j++)
			{
				if(!b[j][i])
		    	{
			    	ap[j]=1;
			    }
			}
		}
	}
}
int ans()
{
	int end=0;
	for(int i=31;i>=0;i--)
	{
		if(location[i])
		{
			long long y=1;
			for(int j=0;j<i;j++)
			{
			    y*=2;
			}
			end+=y;
		}
	}
	return end;
}
int main()
{
	cin>>n>>goal;
	ap.resize(n);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		for(int j=31;j>=0;j--)
		{
			long long y=1;
			for(int k=1;k<=j;k++)
			{
			    y*=2;
			}
			if(x>=y)
			{
				x-=y;
				b[i][j]=1;
			}
		}
	}
	location.resize(31);
	for(int i=0;i<31;i++)
	{
		location[i]=0;
	}
	running_ap();
	cout<<ans();
	return 0;
}