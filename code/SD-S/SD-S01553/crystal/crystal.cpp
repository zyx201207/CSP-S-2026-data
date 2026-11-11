#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1)-(sum[i]-sum[j-1])>m){
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
