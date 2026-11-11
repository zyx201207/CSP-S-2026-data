#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
const int MAX=1e18+10;
int _=1;
int n,m,l,r,mid,minx=0,minn,ans;
int a[N],sum[N];
bool check(int x){
	minn=MAX;
	for(int i=x;i<=n;i++){
		int t=sum[i]-sum[i-x+1]-(i-x)*(a[i]-a[i-x+1]);
		minn=min(minn,t);
	}
	if(minn<=m) return 1;
	else return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) minx=min(minx,a[i]);
	}
	//for(int i=1;i<=n;i++){
		//a[i]+=abs(minx);
	//}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	l=1;r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,l=mid+1;
		}
		else r=mid-1;
		//cout<<l<<" "<<r<<'\n';
	}
	cout<<ans;
	return ;
} 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cin>>_;
	while(_--) solve();
	return 0;
}
