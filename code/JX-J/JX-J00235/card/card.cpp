#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int b[1005],c[1005];
	cin>>n>>m;
	int t=n*(n-1)/2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}
