#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+s[i]*(i-1);
	//for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	int l=1,r=1;
	while(l<=r&&r<=n){
		if(l==r){
			ans=max(ans,1LL);
			r++;
			continue;
		}
		int k=s[r]-s[l-1]-(a[r]-a[l-1])*(l-1);
		if(k<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
