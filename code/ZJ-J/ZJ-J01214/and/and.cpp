#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010];

int intand(int a,int b)
{
	int c[100]={0},p=0;
	int ret=0;
	while(a>0&&b>0)
	{
		int aa=a%2,bb=b%2;
		c[++p]=int(aa and bb);
		a/=2,b/=2;
	}
	for(int i=p;i>=1;i--)
		ret=ret*2+c[i];
	return ret;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=intand(ans,a[i]);
		cout<<ans;
		return 0;
	}
	
	else if(m==2)
	{
		ans=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(intand(a[i],a[j]),ans);
		cout<<ans;
		return 0;
	}
	
	else
	{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
			ans=intand(ans,a[i]);
		cout<<ans;
	}
	return 0;
}
