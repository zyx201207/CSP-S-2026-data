#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=500005;
int a[N];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,sum=0;
	for(int r=1;r<=n;r++){
		sum+=a[r];
		while((r-l+1)*a[r]-sum>m){
			sum-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
