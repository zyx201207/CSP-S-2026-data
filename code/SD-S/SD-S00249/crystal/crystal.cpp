#include<bits/stdc++.h>
#define int long long
#define ll long long
#define N 500050
#define M 1
using namespace std;
ll n,m,a[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,sy=0;
	for(int r=2;r<=n;r++){
		sy+=(r-l)*(a[r]-a[r-1]);
		while(sy>m){
			sy-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1); 
	}
	cout<<ans<<endl;
	return 0;
}
//Oct31==Dec25?
