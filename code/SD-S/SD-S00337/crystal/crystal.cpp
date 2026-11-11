#include<bits/stdc++.h>
#define int long long
#define fr first
#define sc second
using namespace std;
const int N=5e5+5;

int n,m,s,ans;
int a[N],sa[N];
/*
关键词 
114514 ccf 奶龙 
luogu_uid=785636 
这个为啥是单调的啊？
算了，不会证明，样例确实都是单调的，感性理解也挺对的 
我选择相信出题人
*/
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sa[i]=sa[i-1]+a[i];
	for(int i=1,j=1; i<=n; i++) {
		while(sa[i]-sa[j-1]+m<(i-j+1)*a[i])j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}

signed main() {
	int T=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
多测要清空
注意 ll 和 double 精度
ds 要 build
不要饭堂qwq
*/
