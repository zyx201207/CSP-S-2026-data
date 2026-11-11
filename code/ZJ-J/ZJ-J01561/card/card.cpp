#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005]={0};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	int t=n;
	while(t--)
	{
		int b[500005]={0};
		for(int i=t;i<n;i++)
		{
			int x=-1;
			for(int j=t;j<i;j++)
			{
				if(a[i]==b[j])x=j;
			}
			if(x==-1)
			{
				b[i]=a[i];
				continue;
			}
			for(int j=x+1;j<i;j++)b[i]=0;
		}
		for(int i=t;i<n;i++)
		{
			if(b[i]==0)break;
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
