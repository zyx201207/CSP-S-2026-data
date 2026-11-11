#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e5+10;
int n,m,a[N],sum[N],cur,ans;
bool check(int len,int r){
	return len*a[r]-(sum[r]-sum[r-len])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))l=mid+1;
			else r=mid-1;
		}ans=max(ans,l-1);
	}cout<<ans;
	return 0;
}
