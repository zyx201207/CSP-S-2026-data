#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=10005;
long long c,t,n,d,x[maxn],s[maxn],f[maxn][maxn],mm[maxn][maxn];

int main() {
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t-->0) {
		cin >> n >> d;
		for (int i=1;i<=n;i++) {
			cin >> x[i];
			//s[i]=s[i-1]+x[i];
		}
		int ans=0;
		for (int l=1;l<n;l++) {
			for (int i=1;i<=n-l;i++) {
				int j=i+l;
				//cout << "C" << endl;
				if (x[j]-x[i]<=d) {
					f[i][j]=1;
					mm[i][j]=1;
					continue;
				}
				mm[i][j]=99999999;
				for (int k=i+1;k<j;k++) {
					if (mm[i][k]+mm[k][j]<mm[i][j]) {
						mm[i][j]=mm[i][k]+mm[k][j];
						f[i][j]=f[i][k]*f[k][j];
					}else if (mm[i][k]+mm[k][j]==mm[i][j]) {
						f[i][j]+=f[i][k]*f[k][j];
					}
					if (f[i][j]>=3) f[i][j]=3;
				}
				//cout << f[i][j] << endl;
				if (f[i][j]==2) ans++;
			}
		}
		cout << ans << endl;
	}
}
