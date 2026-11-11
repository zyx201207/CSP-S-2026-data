#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,k,ans;
ll a[N],c[N],sum[N],res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+c[i];
	}
	k=1;
	for(int i=1;i<=n;i++){
		res+=c[i]*(i-k);
		while(res>m){
			res-=(sum[i]-sum[k]);
			k++;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans<<endl;
	return 0;
}