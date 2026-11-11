#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int b=a[n-1];
	for(int i=n-2;i>=m-1;i--){
		b&=a[i];
	}
	cout<<b;
	return 0;
}
