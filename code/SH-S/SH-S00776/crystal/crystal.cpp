#include<bits/stdc++.h>
typedef long long ll;
using std::cin;
using std::cout;
constexpr int N=5e5+9;
int n,ans=1;
ll m,a[N],energy;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(int l=1,r=2;r<=n;r++){
		energy+=(r-l)*(a[r]-a[r-1]);
		while(energy>m&&l<r){
			energy-=a[r]-a[l++];
		}
		ans=std::max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

// TIME: O(n)
// 100pts!!!