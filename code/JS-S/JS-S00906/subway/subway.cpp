#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=5e2+10;
const int Q=1e5+10;
long long w[M];
//in out time
long long t[M][N];
// a'zhan  :  ting -> tai 's time
long long l[Q],r[Q];
int main()
{
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
		cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long a;
			cin>>a;
			cin>>t[a][i];
		}
	}
	
	for(long long i=1;i<=q;i++)
		cin>>l[i]>>r[i];
	return 0;
}
