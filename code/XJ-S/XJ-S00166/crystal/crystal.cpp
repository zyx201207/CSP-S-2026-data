#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int n,m,a[N],pf[N],delta[5555][5555];
signed main() {
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;cin>>a[1];
	for(int i=2;i<=n;i++) {cin>>a[i];pf[i]=a[i]-a[i-1];}
	if(n<=5000) {
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=i;j++) {
				delta[j][i]=a[i]-a[j];
			}
			for(int j=i+1;j<=n;j++) {
				delta[i][j]=a[j]-a[i];
			}
		}	
		int cnt=0,maxn=-0x3f3f3f3f,t=m;
		for(int i=1;i<=n;i++) {
			cnt=0,t=m;
			for(int j=1;j<=i;j++) {
				if(t>=delta[j][i]) {
					cnt++;t-=delta[j][i];
				}
			}
			maxn=max(maxn,cnt);
		}	
		cout<<maxn;
	}
	else {
		int cs=pf[2],kfc=1;
		for(int i=2;i<=n;i++) {
			if(pf[i]!=cs) {kfc=0;break;}
		}
		if(kfc==1) {
			int sum=cs,cnt=0;
			while(m>=0){
				m-=sum;++cnt;sum+=cs;
			}
			cout<<cnt;return 0;
		}
	} 
	return 0;
} 
