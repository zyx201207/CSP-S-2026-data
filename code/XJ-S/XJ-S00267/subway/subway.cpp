#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,a[10000005],b[10000005],q,c,p,k,t[10000005],sum,w[100000005],x[10000005],l,r,ti;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cout<<0;
	cin>>c>>n>>m>>p>>q;
	for(i=1;i<=m;i++)
	cin>>a[i];
	cin>>k;
	for(j=1;j<=m;j++)
	{
		cin>>x[j]>>w[j];
	}
	for(i=1;i<=q;i++)
	{
		cin>>l>>r;
		sum+=w[i]+a[i];
	}
	cout<<sum;
}
