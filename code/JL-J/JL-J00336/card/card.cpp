#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,tot,ans[N],a[N],tmp[N],fir[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		tot=0;
		for(int j=i;j<=n;j++)
		{
			if(!fir[a[j]])
			{
				tmp[++tot]=a[j];
				fir[a[j]]=tot;
			}
			else
			{
				tot=fir[a[j]];
			}
		}
		for(int j=1;j<=tot;j++)
		{
			ans[a[j]]++;
			cout<<a[j]<<" ";
		}
		cout<<"\n";
		memset(fir,0,sizeof(fir));
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}