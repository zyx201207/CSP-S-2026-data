#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],sum[N],ans=0;
bool check(int x,int y){
	int t=(y-x+1)*a[y]-sum[y]+sum[x-1];
	if(t<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,t=i;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1; t=mid;
			}else l=mid+1;
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}
