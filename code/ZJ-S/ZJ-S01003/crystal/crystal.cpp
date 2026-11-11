#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll a[N];
ll m,s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r;
	for(r=2;r<=n;r++){
		m-=(r-1)*(a[r]-a[r-1]);
		if(m<0) break;
	}
	m+=(r-1)*(a[r]-a[r-1]);
	r--;
	ans=r-l+1;
	while(r<n){
		r++;
		m-=(r-l)*(a[r]-a[r-1]);
		while(l<=r&&m<0){
			m+=(a[r]-a[l++]);
		}
		if(m>=0) ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}

