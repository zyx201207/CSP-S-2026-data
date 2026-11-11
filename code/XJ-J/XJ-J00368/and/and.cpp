#include<bits/stdc++.h>
using namespace std;
int n,m,max1=0;
int a[100005]={};
int main()
{
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
	        max1=max(max1,(a[i]&a[j]));
		}
	}
	cout<<max1;
}