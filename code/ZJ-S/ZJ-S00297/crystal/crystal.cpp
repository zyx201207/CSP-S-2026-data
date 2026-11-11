#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=5e5+5;
int n,m,a[Maxn];
int T[Maxn];
int Answer;
inline bool Check(int p) {
	int tmp=(p-1)*a[p]-T[p-1];
	if(tmp>m)
		return 0;
	else
		return 1;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(register int i=1; i<=n; ++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(register int i=1; i<=n; ++i)
		T[i]=T[i-1]+a[i];
	int l=1,r=n,mid,tmp_p=0;
	while(l<=r) {
		mid=(l+r)>>1;
		if(Check(mid)) {
			tmp_p=mid;
			l=mid+1;
		} else
			r=mid-1;
	}
	int nw_p;
	for(register int i=tmp_p; i<=n&&a[i]==a[tmp_p]; ++i)
		nw_p=i;
	Answer=nw_p;
	int tmp=nw_p,flg=1;
	for(register int len=tmp; len<=n&&flg; ++len) {
		flg=0;
		for(register int l=1; l<=n-len+1; ++l)
			if(len*a[l+len-1]-(T[l+len-1]-T[l-1])<=m) {
				Answer=len;
				flg=1;
				break;
			}
	}
	cout<<Answer<<endl;
	return 0;
}