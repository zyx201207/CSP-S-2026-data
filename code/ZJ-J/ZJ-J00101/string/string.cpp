#include <bits/stdc++.h>
using namespace std;
struct qj{
	long long l;
	long long r;
	char ch;
}a[200005];
int n;
long long zn=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	a[0].r=0;
	for(int i=1;i<=n;i++){
		long long k;
		cin >> k >> a[i].ch;
		a[i].l=a[i-1].r+1,a[i].r=a[i].l+k-1;
		zn+=k;
	}
	long long lzz=1,rzz=n;
	long long ans=0;
	for(long long l=1,r=zn;l<r;){
		long long k=min(a[lzz].r-l,r-a[rzz].l);
		l+=k;
		r-=k;
		ans+=(a[lzz].ch!=a[rzz].ch?k:0);
		l++,r--;
		if(lzz<n&&l>a[lzz].r)lzz++;
		if(rzz>1&&r<a[rzz].l)rzz--;
		ans+=(a[lzz].ch!=a[rzz].ch?1:0);
	}
	cout << ans;
	return 0;
}