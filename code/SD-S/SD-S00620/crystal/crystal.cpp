#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define ys ios::sync_with_stdio(0);
#define mc cin.tie(0);
#define zmdNB cout.tie(0);
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,q,t,a[N],sum,ans;
ull co;
vector<int> s;
queue<int> d;
map<int,int> cnt;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ys mc zmdNB
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s.push_back(a[i]);
		cnt[a[i]]++;
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	ans=cnt[s[0]];
	int cn=cnt[s[0]];
	for(int i=1;i<=cn;i++)d.push(s[0]);
	for(int i=1;i<(int)s.size();i++) {
		co+=d.size()*(s[i]-s[i-1]);
		while(co>(ull)m&&!d.empty()) {
			co-=s[i]-d.front();
			d.pop();
		}
		ans=max(ans,(int)d.size()+cnt[s[i]]);
		int cn=cnt[s[i]];
		for(int j=1;j<=cn;j++)d.push(s[i]);
	}
	cout<<ans;
	return 0;
}
