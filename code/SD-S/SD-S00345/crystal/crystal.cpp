#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+86;
const int INF=1e18;
typedef long long ll;
int a[N];
int s[N];
int n,m;

signed main(){
	IOS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1;int r=1;
	int ans=0;
	for(;r<=n;r++){
		while(r!=n&&a[r+1]==a[r]){
			r++;
		}
		int need=(r-l+1)*a[r];
		int fact=s[r]-s[l-1];
		while(need-fact>m){
			l++;
			need=(r-l+1)*a[r];
			fact=s[r]-s[l-1];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

