#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n,m;
ll a[N];
ll pre[N];
ll ans;
ll sum;
bool check(int x,int lst){
	ll cnt=0;
	cnt=pre[lst]-pre[x]-((x-1)*(a[lst]-a[x]));
//	cout<<cnt<<" "<<x<<" "<<lst<<'\n';
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i-1,sum=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				sum=(i-mid);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,sum+1);
	}
	cout<<ans<<'\n';
	return 0;
}
