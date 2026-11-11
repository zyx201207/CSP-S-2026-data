#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,m,k=0,z=0;
int zz[maxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%d",&zz[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		z=(zz[i] & zz[j]);
		if(z>k) k=z;
	}
	cout<<k;
	return 0;
}
