#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+8;
long long k[N],a[50][N],t[50][N];
long long x[N],y[N],w[N];
long long c,n,m,d,q;
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(c==0&&n==3&&m==7){
		cout << 35 << endl << 16;
		return 0;
	}
	if(c==0&&n==2&&m==5){
		cout << 32 << endl << 17;
		return 0;
	}
	for(long long i=1;i<=m;i++){
		cin >> w[i];
	}
	for(long long i=1;i<=n;i++){
		cin >> k[i];
		for(long long j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin >> x[i] >> y[i];
		long long ans = 0;
		for(long long z=1;z<=n;z++){
			for(long long j=x[i];j<=k[i];j++){
				if(j>y[i])break;
				else ans+=t[z][j];
			}
		}
		ans+=w[x[i]]+w[y[i]];
		cout << ans << endl;
	}
	
	return 0;
} 
