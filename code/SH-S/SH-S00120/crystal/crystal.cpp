#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int nlist[n];
	for (int i=0;i<n;i++)
		scanf("%d",&nlist[i]);
	double x=1,a=0;
	while (a<=m)
	{
		a += x;
		x += 1;
	}
	a -= x;
	a += 1;
	printf("%e",a);
	return 0;
}
