#include <bits/stdc++.h>
using namespace std;
int n,l,r;
long long a[200005],ans,sl,sr;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	c[0]='@',c[n+1]='@';
	while(l<r)
	{
		if(sl<sr)ans+=min(a[++l],sr-sl)*(c[l]!=c[r]),sl+=a[l];
		else ans+=min(a[--r],sl-sr)*(c[r]!=c[l]),sr+=a[r];
	}
	printf("%lld",ans);
	return 0;
}