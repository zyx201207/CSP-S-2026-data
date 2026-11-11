#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}else if(m==2){
		long long ans=0;
		for(long long i=0;i<n;i++){
			for(long long j=0;j<n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else{
		long long ans=1;
		for(long long i=0;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
