#include<bits/stdc++.h>
using namespace std;
long long res=0;
long long n,m;
long long a[500005];
long long anss;
long long ans=0;
long long val[500005];
long long check(long long x){
	long long mm=m;
	ans=0;
	for(int i=1;i<=n;i++){
		val[i]=abs(a[i]-x);
	}
	sort(val+1,val+1+n);
	for(int i=1;mm-val[i]>=0&&i<=n;i++){
		
		ans++;
		mm-=val[i];
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long anss=check(a[i]);
		if(anss>res){
			res=anss;
		}
	}
	printf("%lld",res);
	return 0;
}
