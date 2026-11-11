#include<bits/stdc++.h>
using namespace std;

int ux;

int n;
long long m;
long long a[500006];

long long l,r,mid;
long long ans;

void why_er()
{
	l=0;
	r=n+1;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ux=scanf("%d%lld",&n,&m);
	if(ux!=2) return 1;
	for(int i=1;i<=n;i++)
	{
		ux=scanf("%d",a[i]);
		if(ux!=2) return 0;
	}
	sort(a+1,a+n+1);
	why_er();
	printf("%lld",&ans);
	return 0;
} 
