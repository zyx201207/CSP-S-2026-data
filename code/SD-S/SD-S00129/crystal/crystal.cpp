#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
const int N=5e5+10;
int n;
long long sum[N],a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		//¶þ·Ö
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(((1ll*(i-mid+1)*a[i])-(sum[i]-sum[mid-1]))<=m) r=mid-1;
			else l=mid+1;
		} 
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}

