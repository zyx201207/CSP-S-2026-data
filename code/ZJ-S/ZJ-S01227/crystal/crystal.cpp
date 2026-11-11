#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
}