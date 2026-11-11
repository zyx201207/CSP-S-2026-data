#include<bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int n,m;
int a[N];
int ans,res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1]-1;
	for(int i=1,j=1;i<=n;i++){
		res=res+(i-j)*(a[i]-a[i-1]);
		while(res>m){
			res-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
