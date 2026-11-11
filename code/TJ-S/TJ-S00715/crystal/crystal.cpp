#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
typedef long long ll;
ll n,m;
ll a[N],sum[N];
 
bool check(int xx){
	ll cnt=0x7f7f7f7f7f7f7f7f;
	for(int i=1;i+xx-1<=n;i++){
		int j=i+xx-1;
		cnt=min(cnt,xx*a[j]-(sum[j]-sum[i-1]));
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	int l=1,r=n;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 
