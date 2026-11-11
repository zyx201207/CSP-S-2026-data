#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],cha[500005],ans,sum[500005],qj[500005],maxn,lo;
long long qjqj(long long r){
	long long dq=qj[r],mid=r;
	while(dq>m){
		dq-=sum[mid];
		mid--;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=2;i<n;++i){
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2]))lo=1;
	}
	for(int i=1;i<n;++i){
		cha[i]=a[i]-a[i-1];
	}
	if(lo==0){
		maxn=(m/cha[1]);
		int j=0;
		while(ans<maxn){
			++j;
			ans+=j;
		}
		printf("%lld",j);
		return 0;
	}
	for(int i=1;i<n;++i){
		sum[i]=cha[i]+sum[i-1];
	}
	for(int i=1;i<n;++i){
		qj[n-1]+=(i*cha[i]);
	}
	for(int i=n-2;i>=1;--i){
		qj[i]=qj[i+1]-((i+1)*cha[i+1]); 
	}
	for(int i=1;i<n;++i){
		maxn=max(maxn,qjqj(i));
	}
	printf("%lld",maxn+1);
	return 0;
}