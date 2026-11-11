#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=5e5+5;
int n,m,l,r,mid,a[mx],b[mx],s[mx],ans;
int ef(int k){
	int l=1,r=k,ans=k;
	while(l<r){
		int mid=(l+r)/2;
		if(s[mid]-s[k]-(k-mid+1)*b[k]<=m)ans=min(ans,mid),r=mid;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[n]-a[i];
	for(int i=n-1;i>=1;i--)s[i]=s[i+1]+b[i];
	for(int i=1;i<=n;i++){
		int pos=ef(i);
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
