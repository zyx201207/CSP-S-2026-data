#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	long long power[n];
	long long k = m;
	for(long long i = 0;i<n;i++){
		cin>>power[i];
	}
	for(long long i = 0;i<n-1;i++){
		if(power[i]>power[i+1]){
			long long mid = power[i];
			power[i] = power[i+1];
			power[i+1] = mid;
		}
	}
	long long ans = 0;
	for(long long i = 1; i<n;i++){
		k = m;
		long long ls_ans = 1;
		if(power[i]-power[i-1]>=k){
			continue;
		}
		for(long long j = i-1;j>=0;j--){
			if(k>=power[i]-power[j]){
				k-=power[i]-power[j];
				ls_ans++;
				if(k == 0){
					if(ls_ans>ans){
						ans = ls_ans;
					}
				}
			}else{
				if(ls_ans>ans){
					ans = ls_ans;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
