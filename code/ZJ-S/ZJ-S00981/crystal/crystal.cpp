#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long arr[N];
long long a1[N];
long long a2[N];
int n;
long long m;
bool cmp(long long x,long long y){
	return x>y;
}
bool f(int l,int r){
	return ((a2[r]-a2[l-1]-a1[l]*(r-l+1))<=m);
}
long long erfen(int l,int r){
	int ll=l;
	long long ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(f(ll,mid)){
			ans=mid-ll+1;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr+1,arr+n+1,cmp);
	for(int i=2;i<=n;i++){
		a1[i]=arr[i-1]-arr[i];
		a1[i]+=a1[i-1];
	}
	for(int i=2;i<=n;i++){
		a2[i]=a1[i]+a2[i-1];
	}
	long long ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,erfen(i,n));
	}
	printf("%lld",ans);
	return 0;
}