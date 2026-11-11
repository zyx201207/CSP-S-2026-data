#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
long long f[5001][5001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)
	    scanf("%lld",&a[i]);
	for(int i = 1;i <= n;i++)
	    f[i][1] = a[i];
	for(int i = 2;i <= n;i++){
		for(int j = 2;j <= m;j++){
			for(int k = 1;k <= n;k++){
				f[i][j] = max(f[i - 1][j],(f[i - 1][j - 1] & a[k]));
			}
		}
	}
	printf("%lld",f[n][m]);
	return 0;
}
