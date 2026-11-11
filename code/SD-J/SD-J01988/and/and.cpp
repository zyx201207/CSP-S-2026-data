#include<bits/stdc++.h>
using namespace std;
int m,n,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1) {cout<<0;return 0;}
	bool nm=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) nm=false;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
} 
