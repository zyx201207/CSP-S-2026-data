#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const long long inf=1e18+5;
int c,T;
int n;
long long d;
long long a[N];
long long f1[N][N],f2[N][N];
void solve() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f1[i][j]=inf;
			f2[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(a[j]-a[i]<=d) {
				f1[i][j]=1;
				f2[i][j]=1;
			}
		}
	}
	for(int len=3; len<=n; len++) {
		for(int l=1; l+len-1<=n; l++) {
			int r=l+len-1;
			for(int k=l+1; k<r; k++) {
				if(a[k]-a[l]>d)break;
				if(f1[l][k]+f1[k][r]<f1[l][r]) {
					f1[l][r]=f1[l][k]+f1[k][r];
					f2[l][r]=f2[l][k]*f2[k][r];
//					cout<<k<<'\n';
				} else if(f1[l][k]+f1[k][r]==f1[l][r]) {
//					++f2[l][r];
					f2[l][r]+=f2[l][k]*f2[k][r];
//					cout<<k<<'\n';
				}
			}
//			cout<<l<<' '<<r<<" "<<f1[l][r]<<' '<<f2[l][r]<<"\n";
		}
	}
	long long ans=0;
	for(int l=1; l<=n; l++) {
		for(int r=l; r<=n; r++) {
			if(f2[l][r]==2)
				++ans;
		}
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4


*/
