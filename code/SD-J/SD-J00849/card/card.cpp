#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
map<int,int> mp;
int v[N],cnt=1;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		cnt=1;
		for(int j=1;j<=n;j++) v[j]=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=cnt;k++)
			{
				if(v[k]==a[j])
				{
					cnt=k;
					break;
				}
			}
			v[cnt++]=a[j];
		}
		for(int j=1;j<cnt;j++) mp[v[j]]++; 
	}
	for(int i=1;i<=m;i++) printf("%lld ",mp[i]);
	return 0;
}

