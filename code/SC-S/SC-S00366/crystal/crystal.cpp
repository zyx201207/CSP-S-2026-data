#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;

long long n,m,q;
long long a[N];
long long ans=-1;

void f(long long l,long long r,long long q){
	if(l>=r)return;
	long long mid=(l+r)/2;
	long long tot1=q*mid*(mid+1)/2,tot2=q*mid*(mid-1)/2;
	if(tot1<=m || tot2<=m)ans=max(ans,mid);
	f(mid+1,r,q);
	return;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long q=a[2]-a[1];
	f(1,n,q);
	printf("%lld",ans);
	return 0;
} 