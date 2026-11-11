#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool cmp(long long x,long long k){
	return((k-x+1)*(a[k]-a[k-1])-(a[k]-a[x-1]))<=m;
} 
long long e(long long k){
	long long l=0,r=k;
	while(l+1<r){
		long long mid=(l+r)/2;
		if(cmp(mid,k)){
			r=mid;
		}else{
			l=mid;
		}
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=n;i>=1;i--){
		ans=max(ans,i-e(i)+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
