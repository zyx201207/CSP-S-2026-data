#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[100005],mx,A,m1;
bool flagaii=1;
long long check(long long x){
	long long gl=a[x],sum=t[a[x]],s=m;
	for(int i=x;i>=1;i--){
		if(a[i]!=a[x]){
			if(s>=a[x]-a[i]) sum++,s-=a[x]-a[i];
			else return sum;
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	m1=m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		t[a[i]]++;
		if(flagaii){
			if(a[i]==i){
				if(m>=i-1) A++,m1-=i-1;
			}else flagaii=0;
		}
	}
	if(flagaii){
		printf("%lld\n",A);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		mx=max(mx,check(i));
	}
	printf("%lld\n",mx);
	return 0;
}