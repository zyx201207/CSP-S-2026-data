#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		int now=a[i];
		for(int j=1;j<m;j++){
			now=(now&a[i+j]);
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
