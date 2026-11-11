#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,ans=0;
long long m;
long long a[500005],b[500005];
vector<int> e;
bool c[500005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	/*for(int i=1;i<=n;i++){
		printf("%lld ",b[i]);
	} 
	puts("");*/
	for(long long i=1;i<=n;i++){
		//printf("%lld ",a[i]);
		long long l=i,r=n+1;
		while(l<r-1){
			long long mid=(l+r)/2;
			if(abs(b[mid]-b[i]-(mid-i)*a[i])<=m){
				l=mid;
			}else{
				r=mid;
			}
			//printf("%lld %lld\n",l,r);
			//printf("%lld %lld\n",l,r);
		}
		
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
	return 0;
}

