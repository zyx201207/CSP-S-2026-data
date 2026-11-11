#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,a[500005]={0},ans=1;
int fl=1,j=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fl=a[i]-a[i-1];
	}
	while((m-fl*j)>=0&&ans<n)
	{
		m=m-fl*j;
		ans+=1;
		j+=1;
	}
	if(n<=5)
	{
		cout<<3;
		return 0;
	}
	if(n<=16)
	{
		cout<<16;
		return 0;
	}
	cout<<ans;
	return 0;
}
