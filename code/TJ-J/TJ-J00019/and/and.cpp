#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	ans=a[n];
	m--;
	for(int i=n-1;m>=1;i--,m--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0; 
}
