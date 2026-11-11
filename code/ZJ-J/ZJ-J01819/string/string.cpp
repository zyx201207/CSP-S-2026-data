#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int MAXN=200010;

struct _{
	int len;
	char c;
};
_ a[MAXN];
vector<_> s,ss,sn;
int n,sum,cnt,ti,ans,xss,jian;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		sum += a[i].len;
	}
	for (int i=1;i<=n;i++){
		ti = i;
		if (cnt+a[i].len>sum/2) break;
		cnt += a[i].len;
		s.push_back({a[i].len,a[i].c});
	}
	if (cnt<sum/2) s.push_back({sum/2-cnt,a[ti].c});
	cnt = 0;
	for (int i=n;i>0;i--){
		ti = i;
		if (cnt+a[i].len>sum/2) break;
		cnt += a[i].len;
		ss.push_back({a[i].len,a[i].c});
	}
	if (cnt<sum/2) ss.push_back({sum/2-cnt,a[ti].c});
	cnt = 0;
	for (int i=0;i<s.size();i++){
		cnt = 0;
		ss[xss].len -= jian;
		while(cnt+ss[xss].len<=s[i].len){
			cnt += ss[xss].len;
			sn.push_back({ss[xss].len,ss[xss].c});
			xss++;
			if (xss>ss.size()-1) break;
		}
		if (xss<ss.size()){
			sn.push_back({s[i].len-cnt,ss[xss].c});
			jian = s[i].len-cnt;
		}else break;
	}
	cnt = 0;
	xss = 0;
	for (int i=0;i<s.size();i++){
		cnt = 0;
		while(cnt+sn[xss].len<=s[i].len){
			cnt += sn[xss].len;
			if (s[i].c!=sn[xss].c) ans += sn[xss].len;
			xss++;
			if (xss>sn.size()) break;
		}
	}
	cout<<ans;
	return 0;
}
