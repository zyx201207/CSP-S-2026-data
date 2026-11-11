#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m,a[N],d[N],s[N];
bool check(int x){
	int cnt=1e18;
	for(int i=x;i<=n;i++){
		cnt=min(cnt,s[i]-s[i-x]-x*d[i]);
	}
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=a[n]-a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+d[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
