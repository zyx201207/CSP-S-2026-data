#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 500005

int n,m,ans,sum;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	while(l<=n){
		if(sum>m||r==n){
			sum-=(a[r]-a[l]);
			l++;
		}
		else if(sum<=m&&r<n){
			int tmp=r-l+1;
			ans=max(ans,tmp);
			sum+=tmp*(a[r+1]-a[r]);
			r++;
		}
		if(sum<=m){
			int tmp=r-l+1;
			ans=max(ans,tmp);
		}
	}
	cout<<ans<<'\n'; 
	return 0;
}
