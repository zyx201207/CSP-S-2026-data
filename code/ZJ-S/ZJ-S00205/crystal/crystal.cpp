#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];//n<=500000
int n,m,ans,s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(l<=r && r<=n){
//		cout<<l<<'\n';
		if(s<=m){
			ans=max(ans,r-l+1);
			r++;
			s=s+(r-l)*(a[r]-a[r-1]);
		}
		else  s=s-a[r]+a[l],l++;
	}
	if(s<=m)  ans=max(ans,r-l+1); 
	cout<<ans;
	return 0;
}
