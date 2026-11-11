#include<bits/stdc++.h>
#define int long long
using namespace std;
//rp++++++++++++++++++++++++++++++++++++++++++
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),prs(n+1,0);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;++i){
		prs[i]=prs[i-1]+a[i];
	}
	int ans=1;
	for(int i=2;i<=n;++i){
		int l=1,r=i;//lr均可
		while(l<r){
			int mid=(l+(r-l)/2);//从mid加到i-1
			int cost=(i-mid)*a[i]-(prs[i-1]-prs[mid-1]);
			//cout<<mid<<" "<<cost<<"\n";
			if(cost>m){
				l=mid+1;
			}else r=mid;
		}
		//cout<<l<<" "<<i<<"*&%\n";
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 