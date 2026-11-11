#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=5e5+5;
ll a[N];
void solve(){
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	__int128 res=m;
	int l=1,ans=1;
	for(int i=1;i<=n;i++){
		__int128 x=a[i]-a[i-1];
		__int128 y=i-l;
		x=x*y;
		res-=x;
		while(res<0) res+=(__int128)a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}