#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Maxn=500010;
int n;
ll m,cnt,a[Maxn],s[Maxn];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n;i++) {
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	s[1]=0;
	for (int i=2;i<=n;i++) {
		s[i]=a[i]-a[i-1];
	}
	int l=1,ans=0;
	for (int r=1;r<=n;r++) {
		cnt+=(r-l)*s[r];
		while (cnt>m&&l<r) {
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout <<ans<<endl;
	return 0;
}

