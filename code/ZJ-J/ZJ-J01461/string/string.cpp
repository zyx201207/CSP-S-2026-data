#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char ch[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>a[i]>>ch[i];
		a[i]+=a[i-1];
	}
	long long cnt=a[n];
	long long midcnt=cnt/2;
	long long ans=0;
	for(int i=1; i<=n; ++i) {
		if(a[i-1]+1ll>midcnt) {
			break;
		}
		int j=upper_bound(a,a+n,cnt-a[i-1]-1)-a+1;
		for(; j>=1; --j) {
			if(a[j]<=midcnt) {
				break;
			}
			long long li=a[i-1]+1ll,ri=a[i],lj=cnt-a[j]+1ll,rj=cnt-a[j-1];
			if(lj>ri) {
				break;
			}
			ri=min(ri,midcnt),rj=min(rj,midcnt);
			if(ch[i]==ch[j]) {
				ans+=max(0ll,min(ri,rj)-max(li,lj)+1ll);
			}
		}
	}
	cout<<1ll*(midcnt-ans)<<endl;
	return 0;
}
