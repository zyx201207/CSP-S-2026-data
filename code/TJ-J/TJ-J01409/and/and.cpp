#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long maxn=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		long long ans=a[i];
		for(int j=i+1;j<m;j++)
		{
				ans=ans&a[j];
		}
		if(ans>=maxn)
		{
			maxn=ans;
		}
	}
	cout<<maxn;
	return 0;
}
