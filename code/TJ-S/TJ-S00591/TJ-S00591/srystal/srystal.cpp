#include<bits/stdc++.h>
#define int long long
#define cen cout << "\n"
#define cs cout << " "
using namespace std;
const int N=5e5+9;
int ar[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> ar[i];
	sort(ar+1,ar+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+ar[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=0,r=i-1;
//		if(i==3){
//			for(int j=0;j<3;j++)cout << (i-1-j)*ar[i]-(sum[i-1]-sum[j]) << " ";
//			cen;
//		}
		while(l<=r){
			int mid=l+r>>1;
			if((i-1-mid)*ar[i]-(sum[i-1]-sum[mid])<=m)r=mid-1,ans=max(ans,(i-mid));
			else l=mid+1;
		}
	}
	cout << ans;
	return 0;
}

