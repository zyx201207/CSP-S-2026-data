#include<bits/stdc++.h>
using namespace std;
int a[3000000];
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int z=1;z<=t;z++)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		int k=d/(a[2]-a[1]);
		int l=max(0,n-(2*k-1));
		cout<<l<<endl;
	}
	return 0;
}
