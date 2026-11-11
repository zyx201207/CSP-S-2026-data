#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,ans,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(((i-1)*a[i]-sum[i-1])<=m && (i*a[i+1]-sum[i])>m){
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}
