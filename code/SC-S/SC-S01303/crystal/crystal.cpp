#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m;
int a[MAXN],cnt[MAXN];
int ans=-1;
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=i; ++j) {
			cnt[j]=a[i]-a[j];
		}
		sort(cnt+1,cnt+1+i);
		int cmp=m;
		int num=0;
		for(int j=1; j<=i; ++j) {
			if(cmp-cnt[j]>=0) {
				cmp-=cnt[j];
				num++;
			} else {
				break;
			}
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}