#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n;
LL m;
LL a[N],s[N];

bool check(int len){
	for(int i=len;i<=n;i++){
		LL tmp=(LL)len*a[i]-(s[i]-s[i-len]);
		if(m>=tmp) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	
	return 0;
}
