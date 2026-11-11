//- Exoplanetary Mirage -
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int flag[N];
int ans[N];
int last[N];
int flag2[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(last,0,sizeof(last));
		memset(flag,0,sizeof(flag));
		memset(flag2,0,sizeof(flag2));
		for(int j=i;j<=n;j++)
		{
			if(last[a[j]]!=0&&!flag[last[a[j]]])
			{
				for(int k=last[a[j]];k<j;k++)
				{
					flag[k]=1;
				}
			}
			last[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			if(!flag[j])
			{
				if(!flag2[a[j]])
					ans[a[j]]++;
				flag2[a[j]]=1;
			}
//			cout<<flag[j]<<' ';
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
//648647291436
//Backward, go backward, go back to the -