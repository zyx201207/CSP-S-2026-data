#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int a[N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int cnt=a[i]&a[i+1];
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

