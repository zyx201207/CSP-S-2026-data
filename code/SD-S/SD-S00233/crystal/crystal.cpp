#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+20;
int n,m,a[N],suff[N];
int suff_2[N],ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;--i)suff[i]=suff[i+1]+a[i+1]-a[i];
	for(int i=n-1;i>=1;--i)suff_2[i]=suff_2[i+1]+suff[i];
	for(int i=1;i<=n;++i){
		if(a[i]==a[i-1])continue;
		int l=1,r=n,gl=a[i],as=i;
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(a[mid]==gl){
				as=mid;
				l=mid+1;
			}
			else if(a[mid]>gl)r=mid-1;
			else l=mid+1; 
		} 
		l=1,r=as;
		int k=a[i]-a[as];
		while(l<=r){
			int mid=l+((r-l)>>1);
			if(suff_2[mid]-suff_2[as]-1ll*(as-mid)*suff[as]+abs(a[as]-gl)*(as-mid+1)<=m){
				r=mid-1;
				ans=max(ans,(as-mid+1));
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
