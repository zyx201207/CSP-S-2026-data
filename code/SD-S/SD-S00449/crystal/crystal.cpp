#include<bits/stdc++.h>
using namespace std;
long long a[500005];
__int128 pre[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	__int128 j=1;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+j*(i-1)*(a[i]-a[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=lower_bound(pre+1,pre+n+1,pre[i]-m)-pre;
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}

