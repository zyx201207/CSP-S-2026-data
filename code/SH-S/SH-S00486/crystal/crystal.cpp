#include<bits/stdc++.h>
using namespace std; 
const int MAXN=500010;
typedef long long ll;
ll a[MAXN],m;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	ll cnt=0,c=0;
	int ans=0;
	bool cgl=0;
	while(l<=r&&r<=n){
		c=a[r];
		if(!cgl) cnt+=(r-l)*(c-a[r-1]);
		cgl=0;
		if(cnt<=m) ans=max(r-l+1,ans),r++;
		else l++,cnt-=(c-a[l]),cgl=1;
	}
	cout<<ans;
	return 0;
}
