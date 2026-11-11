#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e12+5;
int n,m,a[500005],ans,l=1,used,sum;
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int r=1;r<=n;r++){
		sum++;
		used+=1ll*(r-l)*(a[r]-a[r-1]);
		while(used>m){
			sum--;
			used-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

