#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000001],b[100000001];
int main(
{
	freopen("travel,in","r",stdin);
	freopen("travel,out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long name=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<name;k++)
			{
				if(b[i]==a[i])
				{
					for(int b=i;b<name;b++)
					{
						a[i]++;
					}
					name=0;
			}
		}
	}
}
