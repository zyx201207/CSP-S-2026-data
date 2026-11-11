#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],ans;
bool check(int id,int x){
	if((id-x+1)*a[id]-(sum[id]-sum[x-1])<=m)
		return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	a[0]=100000000000000;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,rans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid))
				r=mid-1,rans=min(rans,mid);
			else
				l=mid+1;
		}
		ans=max(ans,i-rans+1);
	}
	cout<<ans;
} 
