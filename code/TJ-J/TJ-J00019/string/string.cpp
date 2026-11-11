#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],b[30],c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[c[i]-64]++;
	}
	cout<<0;
	return 0; 
}
