#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],l,r,sum,m,mid,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=r=1;
	while(r<n){
		r++;
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			l++;
			sum-=a[r]-a[l-1];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}