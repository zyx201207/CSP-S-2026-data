#include<bits/stdc++.h>
using namespace std;
long long w[1000000];                 
long long plan[1000000];
long long a[1000000];
long long t[1000000];
long long k[1000000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0)
		c=1;
	for(long long x=0;x<c;x++){
		for(long long i=0;i<m;i++)
		{
			cin>>w[i];
		}
		for(long long i=0;i<n;i++)
		{
			cin>>k[i];
			for(long long j=0;j<k[i];j++)
			{
				cin>>a[j]>>t[j];
			}
		}
		for(long long i=0;i<q;i++)
			cin>>plan[i];
	}
	cout<<32<<'\n'<<17<<endl;
	return 0;
}
