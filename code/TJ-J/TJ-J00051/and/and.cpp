#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005],M;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	M=a[n];
	for(int i=1;i<=m;i++){
		M=(a[n]&M);
	}
	cout<<M;
	return 0;
} 
