#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int INF=1e18;
int n,m;
int a[N];
__int128 sum[N];
bool check(int mid,int x){
	if((__int128)a[x]*(x-mid+1)-(sum[x]-sum[mid-1])<=(__int128)m){
		return true;
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxa=-INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int res;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				res=(i-mid+1);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
//	cout<<sum[n]<<"\n";
//	cout<<n*maxa<<"\n";
//	cout<<n*maxa-sum[n];
	return 0;
}
