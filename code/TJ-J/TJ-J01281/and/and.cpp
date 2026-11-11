#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=1;i<=m-1;i++){
		a[0]&=a[i];
	}
	cout<<a[0];
	return 0;
} 
