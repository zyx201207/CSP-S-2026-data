#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n,cnt=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int res=(mid-i+1)*a[mid]+sum[i-1]-sum[mid];
			if(res<=m){
				cnt=mid;
				l=mid+1;
			}else r=mid-1;
		}
		ans=max(ans,cnt-i+1); 
	}
	cout<<ans;
	return 0;
}

