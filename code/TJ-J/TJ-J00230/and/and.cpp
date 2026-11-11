#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen(.in,"w",stdin);
	//freopen(.out,"r,",stdout);
	int a[200005] ;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	 sort(a,a+n);
	 int l=0;
	for(int j=n;j>=1;j++){
		l=l&a[j];
	}
	cout<<l;
	return 0;
} 




























































