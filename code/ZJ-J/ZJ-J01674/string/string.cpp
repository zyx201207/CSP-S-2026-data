#include <bits/stdc++.h>
using namespace std;
struct Range
{
	unsigned a;
	char c;
}range[200000];
unsigned n,l,r;
long long unsigned ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%u",&n);
	for(unsigned i=0;i<n;i++) scanf("%u %c",&range[i].a,&range[i].c);
	l=0;r=n-1;
	while(l<r)
	{
		if(range[l].a>range[r].a)
		{
			if(range[l].c!=range[r].c) ans+=range[r].a;
			range[l].a-=range[r].a;
			r--;
		}
		else if(range[l].a<range[r].a)
		{
			if(range[l].c!=range[r].c) ans+=range[l].a;
			range[r].a-=range[l].a;
			l++;
		}
		else
		{
			if(range[l].c!=range[r].c) ans+=range[l].a;
			l++;
			r--;
		}
	}
	printf("%llu",ans);
	return 0;
}
