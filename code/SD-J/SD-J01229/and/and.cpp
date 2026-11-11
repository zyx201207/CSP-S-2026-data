#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	if(m==2)
	{
		int mx=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int t=a[i]&a[j];
				mx=max(mx,t);
			}
		}
		cout<<mx;
		return 0;
	}
	sort(a,a+n);
	cout<<a[n-m];
	return 0;
} 
