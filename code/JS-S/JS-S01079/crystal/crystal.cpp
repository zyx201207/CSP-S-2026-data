#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long max(long long a,long long b){
	if(a>b)return a;
	return b;
}
long long min(long long a,long long b){
	if(a<b)return a;
	return b;
}
bool cmp(long long a,long long b){
	return a<b;
}
int tot;
long long n,m;
long long l,r;
long long maxx=LLONG_MIN,minn=LLONG_MAX;
long long num[MAXN],diff[MAXN];
long long sum[MAXN];
bool check(int k){
	tot=0;
	for(int i=1;i<=n;i++)
	{
		if(k-num[i]<0)break;
		diff[++tot]=k-num[i];
	}
	long long m1=m;
	for(int i=tot;i>=1;i++){
		if(m1<diff[tot])return false;
		m1-=diff[tot];
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+n+1,cmp);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(num[i]-num[i-1]);
	}
	long long l=1,r=n;
	while(l+1<r){
		long long mid=(l+r)/2;
		bool flag=0;
		for(long long i=mid;i<=n;i++){
			if(sum[i]-sum[i-mid]-(i-mid)*(num[i]-num[i-mid])<=m){
				flag=true;
				break;
			}
		}
		if(flag)l=mid;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}
//5 5 1 2 4 8 9 
