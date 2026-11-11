//shuaiyuchenbianxie
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],flaga=1,b[500005],ans[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])flaga=0;
	}
	if(flaga)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
		return 0;
	}
	for(int j=1;j<=n;j++)
	{
		memset(b,0,sizeof(b));
		for(int i=j;i<=n;i++)
		{
			if(b[a[i]]==0)b[a[i]]=i;
			else{
				for(int k=b[a[i]]+1;k<=i-1;k++)
				{
					b[a[k]]=0;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(b[a[i]]!=0)ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
