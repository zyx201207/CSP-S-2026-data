#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
const int N=2e5+10;
using ll=long long;
ll a[N];
ll n,m;
ll mx=-1;
void dfs(int x,ll s,int cnt){
	if(cnt==m){
		mx=max(mx,s);
		return ;
	}
	if(x>n) return ;
	dfs(x+1,s&a[x],cnt+1);
	dfs(x+1,s,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ll ans=-1;
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ll mx=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ll x=(a[i]&a[j]);
				mx=max(mx,x);
			}
		}
		cout<<mx;
		return 0;
	}
	dfs(1,-1,0);
	cout<<mx;
	return 0;
}