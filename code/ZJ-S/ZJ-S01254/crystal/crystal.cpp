#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],ans=1;
int sum[maxn],cnt[maxn];
bool check(int i,int x){
	int res=cnt[i];
	res-=(i-x)*a[i]-sum[i-x];
	if(res<=m){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		cnt[i]=cnt[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]<=m){
			ans=max(ans,i);
			continue;
		}
		int l=1,r=i-1,pos=1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				l=mid+1;
				pos=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,pos);
	}
	cout<<ans;
	return 0;
}
