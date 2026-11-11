#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,a[N],lp,l,rp,r,ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	lp=l=1,rp=n,r=a[n];
	while(lp<rp)
	{
		if(c[lp]!=c[rp])
			ans+=min(a[lp]-l+1,r);
		if(a[lp]-l+1<r)
			r-=a[lp]-l+1,lp++,l=1;
		else if(a[lp]-l+1>r)
			l+=r,rp--,r=a[rp];
		else
			lp++,l=1,rp--,r=a[rp];
	}
	cout<<ans;
	return 0;
}

