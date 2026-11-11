#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int n,s,ans;
long long m,a[N],b[N];
int f(int x){
	long long ans=0;
	for(int i=1;i<x;i++){
		ans=ans+b[i]*i;
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(f(mid)==1){
			l=mid;
		}
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
