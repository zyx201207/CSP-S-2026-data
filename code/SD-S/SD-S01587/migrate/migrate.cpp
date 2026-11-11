#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define pii pair<int,int>
#define ft first
#define sd second
#define db double
const int INF=4e18;
const int N=305;
int cc,T;
int n,d,a[N];
int s[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	AC;
	cin>>cc>>T;
	if(cc>10) {

		while(T--) {
			cin>>n>>d;
			for(int i=1; i<=n; i++)cin>>a[i];
			int p=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					p++;
					break;
				}
			}
			int ss=0;
			for(int i=1;i<=n;i++){
				int t=upper_bound(a+1,a+n+1,a[i]+d)-a;
				s[i]=t-i+1;
				ss+=s[i];
			}
			cout<<n*(n-1)/2*p-ss<<'\n';
		}
		return 0;
	}
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];

		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int res=INF,cnt=0;
				for(int s=0; s<(1<<(j-i-1)); s++) {
					int p=i,fg=1,dis=1;
					for(int k=1; k<=j-i-1; k++) {
						if((s>>(k-1))&1) {
							if(a[i+k]-a[p]>d) {
								fg=0;
								break;
							}
							p=i+k;
							dis++;
						}
					}
//					if(i==1&&j==4)cout<<p<<'|';
					if(a[j]-a[p]>d)continue;
					if(!fg)break;
					if(dis==res)cnt++;
					else if(dis<res)res=dis,cnt=1;
//					cout<<i<<' '<<j<<' '<<dis<<'\n';
				}
				if(cnt==2&&j-i>=2) {
					ans++;
//					cout<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
