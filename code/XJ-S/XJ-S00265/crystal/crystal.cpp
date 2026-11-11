#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010];
long long m;
int ans=0;
bool cmp(long long a,long long b){
	return a<=b;
}
long long s[500010]={0};
bool f(int mid){
	long long cnt=1e18+5;
	for(int i=1;i<=n-mid+1;i++){
		int y=i+mid-1;
		cnt=min(cnt,mid*a[y]-(s[y]-s[i-1])); 
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(f(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
