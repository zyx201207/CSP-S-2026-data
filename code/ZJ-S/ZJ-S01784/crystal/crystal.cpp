#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],r,ans,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	r=1;
	for(int l=1;l<=n;l++){
		while(sum+(a[r+1]-a[r])*(r+1-l)<=m&&r<=n){
			sum+=(a[r+1]-a[r])*(r+1-l);
			r++;
		}
		ans=max(ans,r-l+1);
//		cout<<l<<" "<<r<<" "<<sum<<"\n";
		sum-=a[r]-a[l];
		
	}
	cout<<ans;
	return 0;
}
