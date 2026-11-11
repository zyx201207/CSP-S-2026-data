#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=0x3f3f3f3f;
ll n,m,a[200005],f[200005],k=1,d=32;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	while(d--)
		k*=2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[0]=k-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			f[j]=max(f[j],(f[j-1]&a[i]));
		}
	}
	cout<<f[m];
	return 0;
}
