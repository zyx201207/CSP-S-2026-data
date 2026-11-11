#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
// kan cuo ti le
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	int d=0;
	int ans=1;
	for(;r<=n;r++){
		while(d>m){
			d-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		//cout<<l<<" "<<r<<"\n";
		d+=(a[r+1]-a[r])*(r-l+1);
	}
	cout<<ans<<"\n";
}
