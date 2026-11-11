#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
