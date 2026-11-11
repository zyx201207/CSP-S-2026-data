#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long ll;
int n,m;
ll a[maxn],s[maxn];
ll cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		s[i] = a[i] - a[i-1];
	}
	ll r = 1;
	for(ll l = 1;l<=n;l++){
		while(l<=r && cnt<=m && r <= n){
			cnt += abs(s[r]);
			if(cnt <= m){
				ans = max(ans,r - l + 1);
			}
			r++;
		}
		cnt-=s[l];
	}
	cout<<ans;
	
}
