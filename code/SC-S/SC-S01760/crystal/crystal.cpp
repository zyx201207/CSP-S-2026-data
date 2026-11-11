#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],ans;
inline bool check(int l,int r){
	return (sum[r]-sum[l-1])+m>=a[r]*(r-l+1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;
				res=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
}