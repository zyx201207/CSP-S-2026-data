#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=2e5+5;
int a[maxn];
int ans;
int k[maxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		ans=a[1];
		for(int i=1;i<n;i++)
		{
			ans&=a[i+1];
		}
		cout<<ans;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
    return 0;	
} 
