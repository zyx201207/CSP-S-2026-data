#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000004],sum[5000004],maxn;
bool check(long long mid,long long i){
	//~ cout<<mid<<" "<<i<<" "<<(bool)(sum[i]-(sum[mid-1]+(mid-1)*(a[i]-a[mid-1]))>m)<<endl;
	if(sum[i]-(sum[mid-1]+(mid-1)*(a[i]-a[mid-1]))>m){
		return false;
	}
	else{
		return true;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		sum[i]+=sum[i-1]+(i-1)*(a[i]-a[i-1]);
		long long l=0,r=i+1;
		while(l+1<r){
			long long mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}
			else l=mid;
		}
		maxn=max(maxn,(i-r+1));
	}
	cout<<maxn;
	return 0;
}
