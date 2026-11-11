#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,
	ans=0;
	cin>>n;
	vector<pair<long long,char> > a;
	a.resize(n);
	for(long long i=0;i<n;++i) {
		cin>>a[i].first;
		cin>>a[i].second;
	}
	for(long long i=0;a.size()-i>1;++i) {
		if(a[i].first<a.back().first) {
			ans+=a[i].first*(a[i].second!=a.back().second);
			a.back().second-=a[i].second;
		}
		else {
			ans+=(a[i].second!=a.back().second)*a.back().first;
			a[i].first-=a.back().first;
			a.pop_back();
			--i;
		}
	}
	cout<<ans;
}
