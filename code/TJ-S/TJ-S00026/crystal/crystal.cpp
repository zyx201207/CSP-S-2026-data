#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long abcd(long long z,long long t[500010]){
	long long ans=0;
	long long ac=m;
	for(long long i=0;i<n;i++){
		if(t[i]<=t[z]&&t[z]-t[i]<=ac){
			ac-=(t[z]-t[i]);
			ans++;
		}
	}
	return ans;
}
/*
             /\          ==========
            /  \         |
           /    \        |
		  /      \       |
		 /========\      |
	    /          \     |
	   /            \    |
	  /              \   ==========
*/ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n >> m;
	bool f1=1;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
		if(a[i]!=i+1)f1=0;
	}
	sort(a,a+n);
	bool f2=1;
	if(n<=20001){
		long long max_ans = -1;
		for(long long i=n-1;i>=0;i--){
			max_ans=max(abcd(i,a),max_ans);
		}
		cout<<max_ans;
	}
	if(n>20001&&n<=500000){
		if(m>100000000){
			if(f1){
				long long num=0;
				long long ans=-1;
				for(int i=0;i<n;i++){
					num+=i+1;
					if(num-i-1<m)ans=i+1;
				}
				cout<<ans;
				return 0;
			}
			int sum=a[1]-a[0];
			if(a[2]-sum==a[1]&&a[3]-sum==a[2]){
				long long num=0;
				long long ans=-1;
				for(int i=0;i<n;i++){
					num+=(i+1)*sum;
					if(num-(i+1)*sum<m)ans=i+1;
				}
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
} 
