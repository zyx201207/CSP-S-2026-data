#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=cnt;k++)
			{
				if(b[k]==a[j])
				{
					for(int l=k;l<=cnt;l++)
					{
						b[l]=0;
					}
					cnt=k-1;
				}
			}
			cnt++;
			b[cnt]=a[j];
//			for(int l=1;l<=cnt;l++)
//			{
//				cout<<b[l]<<" ";
//			}
//			cout<<"\n";
		}
		for(int j=1;j<=cnt;j++)
		{
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

