#include <bits/stdc++.h>
using namespace std;

void open_file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

using ll=long long;
constexpr int N=5e5+5;
int n,m,ans=1;
ll a[N],sum[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	open_file("crystal");
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;++i){
		int l=1,r=i;
		while (l<r){
			int mid=(l+r)>>1;
			if (sum[i]-sum[mid-1]+m>=a[i]*(i-mid+1)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*

5 5
1 2 4 8 9

*/
