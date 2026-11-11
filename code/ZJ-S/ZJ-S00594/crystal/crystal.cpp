#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int l=1,r=1;r<n;){
		s+=(r-l+1)*(a[r+1]-a[r]);
		r++;
		if(s>m){
			s-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}