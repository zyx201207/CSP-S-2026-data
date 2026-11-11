#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],sum[1000005];
int query(int l,int r){return sum[r]-sum[l-1];}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1; i<=n; i++){
		int lt=0,rt=i+1;
		while(lt+1<rt){
			int mid=lt+rt>>1;
			if(a[i]*(i-mid+1)-query(mid,i)<=m) rt=mid;
			else lt=mid;
		}
		ans=max(ans,i-rt+1);
	}
	cout<<ans;
	return 0;
}