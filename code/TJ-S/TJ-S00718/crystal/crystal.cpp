#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long h = 1;
	long long l = 0;
	long long sum = m;
	long long a[200001];
	long long ans = 1;
	for(long long i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 0;i<n;i++){
		if(a[i] == a[i+1]){
			h += 1;
		}
	ans = h;
	}
	for(int i = 0;i<n;i++){
		l += a[n-1] - a[i];
	}
	if(l<m){
		ans = n;
		cout<<ans;
		return 0;
	}
	for(long long i = 0;i<n;i++){
		sum = m;
		long long cnt = 0;
		for(long long j = 0;j<n;j++){
			sum += a[i+j];
			cnt += 1;
			if(j<= 0){
				continue;
			}
			if(sum/(j+1) == a[i+j]&&j+1>ans){
				ans = j+1;
			}
	}}
	if(ans==1){
		for(long long i = 0;i<n;i++){
		sum = m-i;
		long long cnt = 0;
		for(long long j = 0;j<n;j++){
			sum += a[i+j];
			cnt += 1;
			if(j<= 0){
				continue;
			}
			if(sum/(j+1) == a[i+j]&&j+1>ans){
				ans = j+1+1;
			}
	}
}
}
	cout<<ans;
	return 0;
} 
