#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long maxv=-1000000010,mm=m;
	for(int i=1;i<=n;i++) {
		long long l=i,cnt=0;
		while(l>=1) {
			if(m-(a[i]-a[l])>=0) {
				m=m-(a[i]-a[l]);
				l--;
				cnt++;
			}
			else break;
		}
		maxv=max(maxv,cnt);
		m=mm;
	}
	cout<<maxv;
	return 0;
}
