#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n,m,a[200005],f[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	f[0]=0b11111111111111111111111111111111;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],f[j-1]&a[i]);
		} 
	}
	cout<<f[m];
	return 0;
}

