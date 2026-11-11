#include<bits/stdc++.h>
#define int long long
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)

constexpr int N=5e5+10;
int n,m,a[N],s[N];

signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
	
	std::cin>>n>>m;
	rep(i,1,n)std::cin>>a[i];
	std::sort(a+1,a+1+n);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	int ans=0;
	rep(i,1,n){
		int l=1,r=i,pos=i;
		while(l<=r){
			int mid=l+r>>1;
			int nd=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
			if(nd<=m)pos=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	std::cout<<ans<<"\n";	
	return 0;
}