#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
unsigned long long n,m,a[N];
signed main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}

