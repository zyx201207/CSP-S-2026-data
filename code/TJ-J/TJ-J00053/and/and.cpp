#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	c=a[n-1];
	for(int i=n-2;i>=m-1;i--){
		c=c&a[i];
	}
	cout<<c;
	return 0;
} 
