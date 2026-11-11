//frepen freope feropen froepen frekpen forepen florren 
//freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen 
//woshimubapei,buhuola!
//freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen 
//freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen 
//freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen 
//freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen freopen 
//SN-S00630
#include<bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define dep(a,b,c) for(int a=b;a>=c;a--)
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
const int N=1e6+5;
int n,m,a[N],s[N],p[25]={1,2},mn=0,ans=0;
int f(int pos){
	int sum=0;
	dep(i,20,0){
		if((sum+p[i]-pos)*a[pos]-s[sum+p[i]]+s[pos]<=m&&sum+p[i]<=n) sum+=p[i];
	}
	return sum-pos+1;
}//¶þ·Ö 
void solve(){
	cin>>n>>m;
	rep(i,1,n) cin>>a[i],mn=min(mn,a[i]);
	if(mn) rep(i,1,n) a[i]-=mn;
	sort(a+1,a+1+n,[](int x,int y){
		return x>y;
	});
	rep(i,1,n) s[i]=s[i-1]+a[i];
	rep(i,1,n){
		if(a[i-1]==a[i]) continue;
		ans=max(ans,f(i));
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	rep(i,2,21) p[i]=p[i-1]*2;
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
