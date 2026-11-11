#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0,test;
	int a[n]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n ;j++)
		{
			test=(a[i]&a[i+1]);
			if(i==j)
				break;
			//cout<<test<<" ";
			if(test>ans)
			{
				ans=test;
			}
			test=0;
		}
	}
	cout<<ans;
}
