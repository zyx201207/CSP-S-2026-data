#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++) a[i]&=a[i];
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
    }
    if(m==n)
    {
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
    }
    if(m==2)
    {
		int sum,ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum=a[i]&a[j];
				ans=max(ans,sum);
		    }
		}
		cout<<ans;
    }
    return 0;
}
