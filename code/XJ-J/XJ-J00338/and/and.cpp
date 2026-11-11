#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000003];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	sort(a,a+n);
	sum=a[n-1];
	for(int i=n-2;i>=n-m;i--){
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}