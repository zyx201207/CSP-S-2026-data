#include <bits/stdc++.h>
using namespace std;
unsigned n,m,a[200000],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%u%u",&n,&m);
	for(unsigned i=0;i<n;i++) scanf("%u",&a[i]);
	for(unsigned lg=30;lg<31;lg--)
	{
		unsigned tmp=ans|(1U<<lg);
		unsigned cnt=0;
		for(unsigned i=0;i<n;i++)
			if((tmp&a[i])==tmp) cnt++;
		if(cnt>=m) ans=tmp;
	}
	printf("%u",ans);
}
