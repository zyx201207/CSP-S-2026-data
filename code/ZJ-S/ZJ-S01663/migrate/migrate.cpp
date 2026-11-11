#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum,p;
long long x1,x2,x;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
for(long long i=1;i<=t;i++)
{
	cin>>n>>d;
	cin>>x1>>x2;
	for(long long j=3;j<=n;j++)
	{
		cin>>x;
	}
p=max(x1-x2,x2-x1);
if(d/p>=2&&n-d/p*2+1>0)cout<<n-d/p*2+1<<endl;
else cout<<0<<endl;
}
	return 0;
}
