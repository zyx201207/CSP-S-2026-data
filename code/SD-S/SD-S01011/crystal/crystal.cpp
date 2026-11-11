#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N];
ll sum[N];
bool check(int l,int r,ll m){
	ll cnt=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
	if(cnt<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=((l+r)>>1);
			if(check(mid,i,m)) r=mid;
			else l=mid+1;
		}
		if(check(l,i,m)){
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans;
	return 0;
} 
