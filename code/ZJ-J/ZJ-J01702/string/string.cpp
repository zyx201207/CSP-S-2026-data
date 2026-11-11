#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x,ans=0;
char u;
vector<pair<char,int> > v;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--) {
		cin>>x>>u;
		v.push_back(make_pair(u,x));
	}
	int i=0,j=v.size()-1;
	while(i<j) {
		if(v[i].first!=v[j].first) {
			if(v[i].second>v[j].second) {
				ans+=v[j].second;
				v[i].second-=v[j].second;
				j--;
			} else if(v[i].second<v[j].second) {
				ans+=v[i].second;
				v[j].second-=v[i].second;
				i++;
			} else {
				ans+=v[i].second;
				i++;
				j--;
			}
		} else {
			if(v[i].second>v[j].second) {
				v[i].second-=v[j].second;
				j--;
			} else if(v[i].second<v[j].second) {
				v[j].second-=v[i].second;
				i++;
			} else {
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a


3
2 a
2 b
1 c


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/ 
