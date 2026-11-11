#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long num[N],cha[N],pre1[N],pre2[N];
long long n,m;
bool check(long long l,long long r){
	long long sum=num[r]*(r-l)-pre2[r-1]+pre2[l-1];
	return (sum<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+n+1);
	for(long long i=1;i<=n;i++){
		cha[i]=num[i]-num[i-1];
		pre1[i]=pre1[i-1]+cha[i];
		pre2[i]=pre2[i-1]+pre1[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=i,r=n;
		while(l<r){
			long long mid=(l+r+1)/2;
			if(check(i,mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,r-i+1);
	}
	printf("%lld\n",ans);
}