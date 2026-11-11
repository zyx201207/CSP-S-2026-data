#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001];
signed main(){
	freopen("and.int","r",stdin);
	freopen("and.out","w",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int t=a[n];
	int s=0;
	for(int i=n-1;i>=1;i--){
		if((t&a[i])!=0) s++,t=(t&a[i]);
		if(s==m) break;
	}
	if(s<m) cout<<0;
	else cout<<t;
	return 0;
}
