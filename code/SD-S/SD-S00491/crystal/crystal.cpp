#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,b=1,ai=1;
	long long m,ans=1;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		m=m-ai*(a[i+1]-a[i]);
		if(m<0)
		{
			m+=a[i]-a[b];
			b++;
			ans--;
			ai--;
			if(m<0)
			{
				ans++;
				break;
			}
		}
		ans++;
		ai++;
	}
	printf("%d",ans);
	return 0;
}

