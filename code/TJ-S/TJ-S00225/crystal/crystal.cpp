#include <bits/stdc++.h>
using namespace std;
long long a[550000];
long long need[550000];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(long long i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	long long head=1;
	long long tail=2;
	long long best=1;
	
	while(tail<=n){
		long long cur=a[tail]-a[tail-1];
		long long len=tail-head;
		need[tail]=len*cur+need[tail-1];
		//printf("%d %d %d %d\n",head,tail,cur,need[tail]);
		while(need[tail]>m){
			need[tail]-=(a[tail]-a[head]);
			head++;
			len--;
			//printf("%d %d %d %d\n",head,tail,cur,need[tail]);
		}
		if(need[tail]<=m){
			best=max(best,len+1);
			//printf("%d\n",best);
		}
		tail++;
	}
	
	printf("%lld\n",best);
	return 0;
}
