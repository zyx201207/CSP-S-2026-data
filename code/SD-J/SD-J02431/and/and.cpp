#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int a[200005];
int ans;
int maxx=INT_MIN;
int n,m;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int maxn=-100000000;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
