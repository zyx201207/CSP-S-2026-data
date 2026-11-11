#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ret,ans;
vector<pair<int, int> >v;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) v.push_back({a[i],i-ret}),ret=i;
	}
	v.push_back({a[n],n-ret});
	for(int i=0;i<v.size();i++){
		int l=i-1,k=m,cnt=v[i].second,is=1;
		while(is){
			if(l>=0){
				if(v[l].second*(v[i].first-v[l].first)>=k){
					cnt+=k/(v[i].first-v[l].first);
					is=0;
				} else {
					k-=v[l].second*(v[i].first-v[l].first);
					cnt+=v[l].second;
					l--;
				}
			} else {
				is=0;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
