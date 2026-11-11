#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0,ans1=0,l=0,r=1;
	a[n+1]=1e12;
	while(r<n){
		while(cnt+(a[r+1]-a[r])*(r-l)>m){
			cnt-=(a[r]-a[l+1]);
			l++;
		}
		while(cnt+(a[r+1]-a[r])*(r-l)<=m){
			cnt+=(a[r+1]-a[r])*(r-l);
			r++;
			
		}
		ans1=max(ans1,r-l);
	}
	cout<<ans1;
	return 0;
}
