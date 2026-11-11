#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int sum[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,now=i;
		while(l<=r){
			int mid=l+r>>1;
			int gt=a[i]*(i-mid)-(sum[i-1]-sum[mid-1]);
//			cout<<i<<' '<<mid<<' '<<gt<<endl;
			if(gt<=m){
				now=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-now+1);
//		cout<<now<<" "<<ans<<endl;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
7 1
9 -5 2 6 0 -3 7 

7 1
-5 -3 0 2 6 7 9
*/

