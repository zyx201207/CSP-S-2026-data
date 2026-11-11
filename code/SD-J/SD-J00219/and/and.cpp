#include<bits/stdc++.h>
using namespace std;
int main()//I believe I will get 1=!!!
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],ans=-2147483648;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans-1;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
