#include<bits/stdc++.h>
using namespace std;
int num[3005];
int a[5005];
vector<int>table;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		table.clear();
		for(int j=i;j<=n;j++)
		{
			bool flag=false;
			for(int i=0;i<table.size();i++)
			{
				if(table[i]==a[j])flag=true;
				if(flag)table[i]=-1;
			}
			table.push_back(a[j]);
		}
		for(int i=0;i<table.size();i++)
		{
			if(table[i]<=m)num[table[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<' ';
	}
	return 0;
}
