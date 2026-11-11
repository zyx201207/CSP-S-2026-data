#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans,sum,lst=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[i]*(i-lst+1)-(s[i]-s[lst-1])>m) lst++;
		ans=max(ans,i-lst+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
