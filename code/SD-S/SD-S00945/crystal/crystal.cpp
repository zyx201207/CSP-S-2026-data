#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	int r=1,tt=0; 
	for(int l=1;l<=n;++l){
		if(l>1) tt-=a[r]-a[l-1];
		while(r<=n){
			if(tt>m){
				ans=max(ans,r-l);
				break;
			}
			++r;
			tt+=(r-l)*(a[r]-a[r-1]);
		}
		if(r>n){
			ans=max(ans,r-l);
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
