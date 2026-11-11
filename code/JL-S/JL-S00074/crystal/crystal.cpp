#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,l,r,a[500010],m,s[500010];
bool ch(int x){
	int ans=1e9+10;
	for(int i=x;i<=n;i++){
		ans=min(a[i]*x-s[i]+s[i-x],ans);
	}
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		int d=(l+r)>>1;
		if(ch(d)){
			l=d+1,ans=d;
		}
		else{
			r=d-1;
		}
	}
	cout<<ans;
	return 0;
}