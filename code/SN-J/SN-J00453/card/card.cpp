#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M],end[M],f[M];
bool flag[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(end[a[i]]!=0)f[i]=end[a[i]];
			end[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			memset(flag,false,sizeof(flag));
			for(int j=n;j>=i;)
			{
				if(flag[a[j]]==false)
				{
					ans[a[j]]++;
					flag[a[j]]=true;
				}
				if(f[j]>=i)j=f[j]-1;
				else j--;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			end[a[i]]=i;
		}
		for(int i=1;i<=m;i++)cout<<end[i]<<" ";
	}
	return 0;
}
