#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,[&](ll a,ll b){
		return a>b;
	});
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[1]-a[i];
	ll ans=0,k=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,maxx=i;
		while(r>=l){
			int mid=(l+r)>>1;
			if(sum[mid]-sum[i-1]-k*(mid-i+1)<=m)
				maxx=mid,l=mid+1;
			else
				r=mid-1;
		}
		ans=max<ll>(ans,maxx-i+1),k+=a[i]-a[i+1];
	}
	cout<<ans<<endl;
	return 0;
}
