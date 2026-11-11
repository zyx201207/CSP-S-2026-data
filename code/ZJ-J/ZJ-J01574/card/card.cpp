#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],f[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)f[j]=a[j];
		for(int j=n-i+1;j>=1;j--)for(int x=j-i;x>=1;x--)if(f[x]==f[j])j=x-1,f[x]=0;
		for(int j=1;j<=n;j++)
		{
			if(f[j]==0)break;
			else ans[f[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
