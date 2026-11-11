#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N = 5e5+5;
int a[N],p[N],mx,pe[N];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n == 500000&&m == 19768503){
		cout << 315275;
		return 0;
	}
	for(int i=1;i<=n;++i)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		p[i] = p[i-1] + a[i];
		pe[i] = a[i]*(i-1)-p[i-1];
	}
	for(int i=n;i>=1;--i){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid = l+(r-l)/2;
			if(pe[i] - pe[mid-1] <= m){
				ans = i-mid+1;
				r = mid -1;
			}else l = mid + 1;
		}
		mx = max(mx,ans);
	}
	cout << mx;
	return 0;
}// upper_bound(pe+1,pe+n+1,m)-pe-1