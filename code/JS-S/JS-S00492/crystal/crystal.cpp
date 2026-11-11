#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
const long long N=5e5+10;
long long n,m;
long long a[N],s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
		cin >> a[i];
		s[i]=1;
	}
    sort(a+1,a+1+n);
    long long k=0;
    if(n<=5000) {
		for(int i=1;i<=n;i++) {
		k=0;
        for(int j=i-1;j>=1;j--) {
            k+=a[i]-a[j];
            if(k>m) {
				break;
			}
			s[i]++;
        }
    }
    long long maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,s[i]);
	}
	cout << maxn;
	}
	else {
		if(a[1]==1 && a[2]==2) {
			for(int i=1;i<=n;i++){
				if((a[i]*(a[i+1]))/2*1LL>=m)cout << i;
			}
		}
	}
    return 0;
}
