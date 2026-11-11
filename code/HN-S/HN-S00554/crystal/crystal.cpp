#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout);
#define int long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N=5e5+5;
int a[N],s[N];
int n,m;
bool cheke(int l,int r){
	int cnt=r-l+1;
	if(cnt*a[r]-(s[r]-s[l-1])<=m) return true;
	return false;
}
signed main(){
	file("crystal");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ll=1,ans=1;
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=a[i]+s[i-1];
		while(!cheke(ll,i)) ++ll;
		ans=max(ans,i-ll+1);
	}
	cout<<ans<<'\n';
	return 0;
}
