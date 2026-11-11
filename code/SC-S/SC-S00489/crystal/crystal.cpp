#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N=5e5+8;
int n,m,a[N],sum[N],l,r,ans=1;
bool check(int p,int q){
	int ri=a[q]*(q-p);
	int le=sum[q-1]-sum[p-1];
	return ri-le<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(check(mid,i)){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
} 