#include<bits/stdc++.h>
using namespace std;
int n,m,a[99999999];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1-m];
	return 0;
}