#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N];
signed main(){
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
} 

