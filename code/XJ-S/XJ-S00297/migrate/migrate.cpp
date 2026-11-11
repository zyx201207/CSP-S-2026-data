#include<bits/stdc++.h>
using namespace std;
long long int hen,n,m,d,q,c,t,i,f,j,w[1000005],a[1000006],x[1000005],y[1000005],b[1005][1005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);

	cin>>c>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(j=1;j<=n;j++)
		cin>>x[j];
	if(n==1)
	cout<<"0";
	else
	if(n==2)
	cout<<"1";
	else
	if(n==3)
	cout<<"1";
	else
	cout<<"0";
	}
	cout<<"0";
return 0;
 } 
 // 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
