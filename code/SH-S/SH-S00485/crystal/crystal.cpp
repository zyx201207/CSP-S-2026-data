#include<bits/stdc++.h>
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],s[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int low=0,high=i;
		while(low+1<high){
			int mid=(low+high)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) high=mid;
			else low=mid;
		}
		ans=std::max(ans,i-high+1);
	}
	std::cout<<ans<<"\n";
}
