#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,l=1,r,ans;
int a[N];
int f[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(r=1;r<=n;r++){
		f[r]=f[r-1]+(r-l)*(a[r]-a[r-1]);
		while(f[r]>m){
			f[r]-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}