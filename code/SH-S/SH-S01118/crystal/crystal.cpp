#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1,a[500001];
__int128 sum[500001];
bool check(int st,int ed){
	__int128 cost=sum[ed];
	if(st>1){
		cost-=sum[st-1]+(__int128)((a[ed]-a[st-1])*(st-1));
	}
	if(cost>m)return false;
	else return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(__int128)((i-1)*(a[i]-a[i-1]));
	}
	for(int i=1;i<n;i++){
		int l=i+1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
			else {
				r=mid-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
