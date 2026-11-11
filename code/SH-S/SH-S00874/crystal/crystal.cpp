#include <iostream>
#include <cstdio> 
#include <climits>
#include <algorithm>
using namespace std;
long long n,m;
long long a[500010],c[500010];
long long mc=LLONG_MIN,mi=LLONG_MAX;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
    	cin >> a[i];
    	mc=max(mc,a[i]);
    	mi=min(mi,a[i]);
	}
	for(int i=1; i<=n; i++)
	{
		c[i]=mc-a[i];
	}
	sort(c+1,c+n+1);
	long long ans=0;
	int la=1;
	for(long long z=0; z<=mc-mi; z++)
	{
		unsigned long long su=0;
		bool ld=true;
		int la_old=la;
		for(int i=la; i<=n; i++)
		{
			su+=c[i]-z;
//			printf("z=%lld, plus %lld (need %lld), su=%lld\n",z,i,c[i]-z,su); 
			if(ld&&c[i]-z>=1)la=i,ld=false;
			if(su>m){ans=max(ans,(long long)i-la_old);/*printf("z=%lld, la=%lld, i=%lld, su=%lld, ans=%lld\n",z,la,i,su,ans);*/break;}
		}
		if(su<=m)
		{
//			printf("not complete£¬su=%lld£¬ans=%lld\n",su,ans);
//			printf("n-la_old+1=%lld\n",n-la_old+1);
		    ans=max(ans,(long long)n-la_old+1);
//		    printf("ans_new=%lld\n",ans);
	    }
	}
	cout << ans << endl;
} 
