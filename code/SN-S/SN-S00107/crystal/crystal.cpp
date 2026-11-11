#include <bits/stdc++.h>

typedef long long ll;

int n;
ll m,a[500010];
ll pre[500010];

inline bool check(int l,int r){
	ll other=pre[r]-pre[l-1];
	ll now=(r-l+1)*a[r];
	return now-other<=m;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
		std::cin>>a[i];
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=i,r=n+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(check(i,mid))
				l=mid;
			else
				r=mid;
		}
		ans=std::max(ans,l-i+1);
	}
	std::cout<<ans<<"\n";
	return 0;
}
