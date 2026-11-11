#include<bits/stdc++.h>
using namespace std;
int a[100005]={0},c[100005]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		c[i]=a[i+1]-a[i];
	}
	sort(c+1,c+n-1);
	int p=0;
	while(m>0)
	{
		p++;
		m-=c[p];
		ans++;
	}
	cout<<ans;
	return 0;
}
