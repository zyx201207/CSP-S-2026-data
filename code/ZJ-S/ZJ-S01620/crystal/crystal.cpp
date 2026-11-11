#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long sum=0,tail=1;
	for(int i=2;i<=n;i++){
		while((m-sum)/(i-tail)<a[i]-a[i-1]){
			sum-=a[i-1]-a[tail];
			tail++;
		}
		sum+=(i-tail)*(a[i]-a[i-1]);
		ans=max(ans,i-tail+1);
	}
	printf("%lld",ans);
	return 0;
}

