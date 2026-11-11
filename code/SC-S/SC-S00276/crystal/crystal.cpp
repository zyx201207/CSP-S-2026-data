#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],ans;
bool check(int d){
	ll sum=0,cnt=0;
	for(int i=1;i<d;i++){
		sum+=a[d]-a[i];
	}
	if(sum<=m) return 1;
	cnt=sum;
	for(int i=d+1;i<=n;i++){
		cnt=cnt-(a[i-1]-a[i-d])+(d-1)*(a[i]-a[i-1]);
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}