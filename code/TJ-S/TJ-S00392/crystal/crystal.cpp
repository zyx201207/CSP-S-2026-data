#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;const long long M=LONG_LONG_MIN;
ll a[N],b[N],n,m,maxn=0,sum=0;
bool check(ll mid){
	int cnt=0;
	for(ll i=1;i<mid;i++){
		cnt+=a[mid]-a[i];
		if(cnt>m){
			return 0;
		}
	}
	clog << "cnt=" << cnt << endl;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool cmp=1;ll sum=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		if(a[i]-a[i-1]!=sum && i>=3){
//			cmp=0;
//		}
//		if(i>=2){
//			sum=a[i]-a[i-1];
//		}
	}
	sort(a+1,a+n+1);
	
//	ll l=1;ll r=n;
//	while(l<r){
//		ll mid=l+(r-l)>>1;
//		if(check(mid)){
//			maxn=max(maxn,mid);
//			r=mid-1;
//		}else{
//			l=mid+1;
//		}
//		clog << "mid=" << mid << " ,l=" << l << " ,r=" << r << endl;
//	}
	for(ll i=2;i<n;i++){
		ll cnt_add=0;
		for(ll j=1;j<i;j++){
			cnt_add+=a[i]-a[j];
			if(cnt_add <= m){
				maxn=max(maxn,j);
			}else{
				break;
			}
		}
	}
	cout << maxn+1 << endl;
	return 0;
} 
