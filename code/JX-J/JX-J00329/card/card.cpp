#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=m;i++)
	{
		long long ans=0;
		for(int j=i;j<=n;j++)
		{
			ans+=a[j];
			if(t[a[j]]!=0)
			{
				for(int k=t[a[j]];k<=j;k++) ans-=a[k];
				t[a[j]]=j;
			}
			else
			{
				t[a[j]]=j;
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}
