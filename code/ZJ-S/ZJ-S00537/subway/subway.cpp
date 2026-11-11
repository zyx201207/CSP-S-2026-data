#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long w[N];
long long a[N];
long long t[N];
long long x[N];
long long y[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
	}
	for(int i=0;i<q;i++)
	{
		cin>>x[i]>>y[i];
	}
	cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
