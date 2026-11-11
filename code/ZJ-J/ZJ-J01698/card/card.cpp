#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],f[300010],s[300010],q[500010],t;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,-1,sizeof f);
		t=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]<=t&&f[a[j]]!=-1)t=f[a[j]]-1;
			q[++t]=a[j];
			f[a[j]]=t;
		}
		for(int j=1;j<=t;j++)s[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
