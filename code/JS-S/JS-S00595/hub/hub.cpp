#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
		int n,k,x,y;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++)
		    scanf("%lld%lld",&x,&y);
		int N=n/2+1;
		if(k==1)printf("%lld\n",N/2);
		else if(k<N)printf("%lld\n",(int)(1ll*ceil(1.0*(N-k)/3);
    return 0;
}
