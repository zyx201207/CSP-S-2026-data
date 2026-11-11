#include <bits/stdc++.h>
#define R register
#define LL long long
using namespace std;
const int N=5e5+10;
int n;
LL m,a[N],s[N];
inline bool check(int x){
	for(R int i=1;i<=n-x+1;i++){
		if(a[i+x-1]*(x-1)-s[i+x-2]+s[i-1]<=m)
			return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(R int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(R int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
