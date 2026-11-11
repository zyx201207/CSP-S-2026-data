#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],sum[maxn],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i+1;
		while(l<=r){
			int mid=(l+r)/2;
			int tot=sum[i]-sum[mid-1];
			int val=(i-mid+1)*a[i]-tot;
			if(val<=m){
				res=mid;
				r=mid-1;
			} else {
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<endl;
	return 0;
}