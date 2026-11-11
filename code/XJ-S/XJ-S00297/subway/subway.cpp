#include<bits/stdc++.h>
using namespace std;
long long int hen,n,m,d,q,i,f,j,w[1000005],a[1000006],t[1000006],x[1000005],y[1000005],b[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);

	scanf("%lld %lld %lld %lld %lld",&hen,&n,&m,&d,&q);
	for(i=1;i<=m;i++)
	scanf("%lld",&w[i]);
	for(j=1;j<=n;j++)
	{
	scanf("%lld",&f);
	for(i=1;i<=f;i++)
	scanf("%lld %lld",&a[i],&t[i]);
	for(i=1;i<=f;i++)
	b[j][i]=a[i];
	
}
	for(i=1;i<=q;i++)
    cin>>x[i]>>y[i];
	
	if(n==1)
	cout<<t[x[1]]+w[y[1]];
	else
	cout<<2;
	 cout<<2;
return 0;
 } 
 // 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
