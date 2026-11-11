#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	long n,a[20050], m;
	cin >> n >> m;
	long sum =1;
	for(long i=0;i<n;i++){
		cin>>a[i];
		if(m == n)
			sum = sum & a[i];
	}
	if(m==n)cout<<sum;
	if(m == 1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	
	
	return 0;
}