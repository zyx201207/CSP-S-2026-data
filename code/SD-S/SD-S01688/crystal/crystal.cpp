#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+1+n);
	
	for(long long i=n;i>=1;i--){
		long long cnt=m,maxn=1;
		for(long long j=i-1;j>=1;j--){
			if(cnt<=0) break;
			cnt=cnt-(a[i]-a[j]);
			if(cnt<0) break;
			else if(cnt==0){
				maxn++;
				break;
			}
			maxn++;
		}
		ans=max(ans,maxn);
	}
	printf("%d",ans);
	return 0;
}
