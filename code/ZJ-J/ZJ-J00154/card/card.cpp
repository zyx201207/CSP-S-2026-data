#include<bits/stdc++.h>
using namespace std;
using uni = unsigned int;
const uni N=5e5+7;
const uni M=3e5+7;
uni n,m,a[N],ans[M],nex[M][21],last[M];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(uni i=1;i<=n;i++) cin>>a[i],last[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			j=last[a[j]];
			ans[a[j]]++;
		}
	}
	for(uni i=1;i<=m;i++) cout<<ans[i]<<' ';
 	return 0;
}
