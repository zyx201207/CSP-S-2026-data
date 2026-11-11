#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],da[300005],v[300005];
bool b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof b);
		int x=0;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]])
			{
				while(v[x]!=a[j])
				{
					da[v[x]]--;
					b[v[x]]=0;
					x--;
				}
			}
			else
			{
				x++;
				v[x]=a[j];
				da[a[j]]++;
				b[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<da[i]<<' ';
	return 0;
}