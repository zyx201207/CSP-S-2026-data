#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],num[500005];
bool cmp (int a,int b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdont);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=0;i<m;i++)
	{
		b[i]=a[i+1]-a[i];
		
	}
	for (int i=0;i<m;i++)
	{
		if (b[i]==0)
		{
			break;
		}
		else
		{
			num[i]=b[i]+b[i+1];
			min(num[i],num[i+1]);
		}
	}
	cout << num[1];
	return 0;
}
