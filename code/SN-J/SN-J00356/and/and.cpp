#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
long long f(long long n,long long m,long long a[100005]){
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n-1);
		printf("%lld",a[n-1]);
		return 0;
	}
	if(m==n){
		long long sum=a[0]&a[1];
		for(int i=2;i<n;i++){
			sum=sum&a[i];
		}
		printf("%lld",sum);
		return 0;
	}
	
	return 0;
}
