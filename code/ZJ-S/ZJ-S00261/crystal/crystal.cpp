#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		b[i]=a[n]-a[i];
		sum[i]=sum[i+1]+b[i];
	}
	for(int i=n;i>=1;i--){
		if(i+1<=n&&a[i]==a[i+1]) continue;
		int diff=a[n]-a[i];
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(sum[mid]-sum[i+1]-diff*(i-mid+1)<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
