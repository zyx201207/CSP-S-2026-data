#include <bits/stdc++.h>
using namespace std;
int x[99999];
int dfs(int y,int z,int o,int sin)
{
	int count=0;
	int num[z-y]={0};
	int num1=0;
	for(int i=y;i<z;i++)
	{
		num[num1]=x[i+1]-x[i];
		num1++;
	}
	num1=0;
	for(int i=0;i<z-y;i++)
	{
		if(o+num[i]<sin&&count<z-2)
		{
			o+=num[i];
			count++;
			dfs(y++,z,o,sin);
		}
		else
		{
			break;
		}
	}
	return count;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int a;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n,d;
		int cnt=0;
		int count=0;
		cin>>n>>d;
		a=n;
		int x[n]={0};
		for(int j=0;j<n;j++)
		{
			cin>>x[j];
		}
		for(int j=0;j<n-1;j++)
		{
			if(x[j+1]-x[j]>d)
			{
				a=j+1;
				for(int k=j+1;k<n;k++)
				{
					x[k]=0;
				}
				break;
			}
		}
		for(int j=0;j<a;j++)
		{
			for(int k=j+2;k<a;k++)
			{
				int ans=dfs(j,k,0,d);
				cnt++;
			}
			if(cnt==2)
		    count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
