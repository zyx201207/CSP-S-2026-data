#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,a[500005],s[500005];
bool check(long long x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(s[i]-s[i-x])<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1;r=n;
	while(l<r){
		mid=l+((r-l+1)>>1);
		if(check(mid)){
			l=mid;
		}else r=mid-1;
	}
	printf("%lld",l);
	return 0; 
}
