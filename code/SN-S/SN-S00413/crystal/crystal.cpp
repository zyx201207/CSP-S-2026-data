#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],m;
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
	int x=m,ans=0;
	for(int i=n,j=n;i;i--){
		while(j>0 && x>=(a[i]-a[j]))x-=(a[i]-a[j]),j--;
		ans=max(ans,i-j);
		x+=(a[i]-a[i-1])*(i-j-1);
	}cout<<ans<<'\n';
	return 0;
}

