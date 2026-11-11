#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long o=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		o=o&a[i];
	}
	cout<<o;
	return 0;
}	
