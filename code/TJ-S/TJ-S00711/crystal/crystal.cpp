#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define MAXN 500010
int a[MAXN],pre[MAXN],m,n;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);pre[0]=a[0];
	for(int i=1;i<n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=0;i<n;i++){
		int l=0,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(pre[i-1]-pre[mid-1])>m)l=mid+1;
			else r=mid;
		}
		int cnt=i-l+1;
		ans=max(ans,cnt);
	}
	cout << ans;
}

