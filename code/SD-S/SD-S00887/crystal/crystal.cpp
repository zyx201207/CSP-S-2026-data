#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long m,a[N],res,n,l=1,r,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(r=1;r<=n;r++){
		res+=(r-l)*(a[r]-a[r-1]);
		while(res>m){
			res-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
