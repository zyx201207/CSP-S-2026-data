#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<pair<ll,ll>>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=__builtin_popcountll(a[i].first);
	}
	sort(a.begin(),a.end(),[](pair<ll,ll> a,pair<ll,ll> b){
		if(a.second!=b.second){
		return a.second>b.second;	
		}
		return a.first>b.first;
	});
	ll ans=a[0].first;
	for(int i=1;i<m;i++){
		ans&=a[i].first;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
