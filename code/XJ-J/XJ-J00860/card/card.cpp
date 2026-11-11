#include<bits/stdc++.h>
using namespace std;
long long n,m,x,v[3000005],f[3000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		v[x]++;
		if(f[x]==0)
			f[x]=i;
	}
	for(int i=1;i<=m;i++)
		cout<<v[i]+f[i]-1<<" ";
	return 0;
}
