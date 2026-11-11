#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0,cnt=0;cin>>n>>m;
	vector<ll>A(n);
	for(int i=0;i<n;i++)cin>>A[i];
	sort(A.begin(),A.end());
	for(ll l=0,r=-1;l<n&&r<n;cnt-=A[l++]){
		while(r<n&&A[r+1]*(r-l+1)-cnt<=m)cnt+=A[++r];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 