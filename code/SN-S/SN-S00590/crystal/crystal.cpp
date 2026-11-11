#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],s[500005];
bool check(int x){
	int cnt=(1ll<<62);
	for(int i=x-1;i<=n-1;++i){
		cnt=min(cnt,a[i+1]*(x-1)-(s[i]-s[i-x+1]));
	}
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
