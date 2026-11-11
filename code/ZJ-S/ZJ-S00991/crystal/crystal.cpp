#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int n,m;
int a[N],s[N];
int check(int x){
	int mi=m+1;
	for(int i=x;i<=n;i++){
		mi=min(mi,a[i]*x-(s[i]-s[i-x]));
	}
	return mi<=m;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}