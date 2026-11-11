/*
 * we must add crystals to one of the values in a[]
 * otherwise we will waste energy
 * with two pointer I can AC
 * 15:07 fix bug,pass samples
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	a[0]=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int l=0,r=1,s=0,cnt=0;//(l,r]
	for (;r<=n;r++){
		s+=(a[r]-a[r-1])*cnt;
		cnt++;
		while (s>m){
			l++;
			s-=(a[r]-a[l]);
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
