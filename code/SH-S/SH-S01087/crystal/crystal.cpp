#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],s[N];
inline bool check(int l,int r){
	if(l==r) return 1;
	return a[r]*(r-l+1)-s[r]+s[l-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int r=1,ans=0;
	for(int l=1;l<=n;l++){
		while(r+1<=n&&check(l,r+1)) ++r;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
