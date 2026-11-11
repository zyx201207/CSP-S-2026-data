#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long c,n,m,d,p,a[N],k,b[510][N],x[N],y[N];
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<2*k;j++)
			cin>>b[i][j];
	}
	for(int i=0;i<p;i++)cin>>x[i]>>y[i];

    return 0;
}
