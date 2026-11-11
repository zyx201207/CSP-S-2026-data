#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long c[500005];
int n;
long long m;
inline bool cheak(int h){
	for(int i=h;i<=n;i++){
		long long k=c[i-h+1]-c[i+1]-b[i]*h;
		if(k<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=1;i--){
		b[i]+=b[i+1];
	}
	for(int i=n-1;i>=1;i--){
		c[i]=b[i]+c[i+1];
	}
	int l=1,r=n,cnt=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(cheak(mid)){
			cnt=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<cnt;
	return 0;
}
//zsy
