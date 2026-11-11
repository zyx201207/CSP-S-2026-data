#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5+5;

int n, m;
ll a[N], sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)scanf("%lld", a+i);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1; i<=n; i++){
		int l=0, r=i, res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(sum[i]-sum[mid])<=m){
				res=min(res,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans, i-res);
	}
	cout << ans;
	return 0;
} 
