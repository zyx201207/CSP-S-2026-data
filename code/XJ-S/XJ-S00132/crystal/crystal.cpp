#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
long long n;
long long m;
long long a[5000005];
bool check(int k){
	long long mink=LLONG_MAX;
	long long res=0;
	for(int i=k;i<=n;i++){
		for(int j=i-k+1;j<i;j++){
			res+=a[i]-a[j];
		} 
		mink=min(mink,res);
	}
	return mink<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=-1;
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l++;
		}
		else{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
