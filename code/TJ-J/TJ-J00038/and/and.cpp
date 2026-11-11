#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    
	long long n,m;
	cin>>n>>m;
	long long a[n+10];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long b=a[n];
	for(long long i=1;i<m;i++){
		b=b&a[n-i];
	}
	cout<<b;
	
	return 0;
}
