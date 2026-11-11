#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long mx;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",a[i]);
	}
	sort(a,a+n);
	mx=a[n-1];
	if(m==1){
		cout<<mx;
		return 0;
	}
	for(int i=n-2;i>=n-m;i--){
		mx=mx&a[i];
	}
	int l=lower_bound(a,a+n,mx)-a-1;
	return 0;
}
