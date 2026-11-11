#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N=500009;
const ll maxA=1e12+1009,M=1e18+1009;
int n;ll m;
ll a[N],sum[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=l+(r-l)/2;
			if((ll)(i-mid+1)*a[i] - (sum[i]-sum[mid-1]) <= m)res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<endl;
	return 0;
}
