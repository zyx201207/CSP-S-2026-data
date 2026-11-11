#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=5e5+10;

int n,m;
int a[MAXN]={};
int d[MAXN]={};
int s[MAXN]={};

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(register int i=1;i<=n-1;i++) {
		d[i]=a[i+1]-a[i];
	}
	s[1]=d[1];
	for(register int i=2;i<=n-1;i++) {
		s[i]=s[i-1]+d[i];
	}
	int ans=1,l=0,r=0,cnt=0;
	for(register int i=1;i<=n-1;i++) {
		if(d[i]<=m) {
			ans=2;
			l=i; r=i;
			cnt=d[i];
			break;
		}
	}
	while(l<=n-1) {
		while(r<=n-2) {
			if(cnt+(r-l+2)*d[r+1]<=m) {
				cnt=cnt+(r-l+2)*d[r+1];
				r++;
			}
			else break;
		}
		if(r-l+2>=ans) ans=r-l+2;
		cnt=cnt-s[r]+s[l-1];
		l++; 
		if(r<l) {
			r=l;
			cnt=d[l];
		}
	}
	cout<<ans<<endl;
	return 0;
} 
