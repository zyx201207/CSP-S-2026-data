#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long num=a[n-1];
	for(long long i=n-m;i<n;i++){
		num&=a[i];
	}
	cout<<num;
	return 0;
}
