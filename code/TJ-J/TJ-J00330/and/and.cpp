#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		int j=i+m,a1=a[i];;
		for(int k=i;k<=j;k++){
			a1&=a[k];
		}
		ans=max(a1,ans);
	}
	cout<<ans;
	return 0;
}
