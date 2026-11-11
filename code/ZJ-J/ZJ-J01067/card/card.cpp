#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,k,l;
int a[300010];
int sum[300010];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		j=i;
		if(a[j]!=a[j+1])
		sum[a[j]]=j;
	}
	for(i=1;i<=m;i++)
	cout<<sum[m]<<' ';
	return 0;
}
