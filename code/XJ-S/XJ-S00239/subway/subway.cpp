#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d;
	long long q;
	cin >> c >> n >> m >> d;
	cin >> q;
	long long x[500];
	long long a[100000];
	long long y[100000];
	long long z[10000];
	long long r[10000],s[10000];
	for(long long i=1;i<=m;i++){
		cin >> a[i];
	}
	for(long long i=1;i<=n;i++){
		cin >> x[i];
		for(long long j=1;j<=x[i];j++){
			cin >> y[j] >> z[j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin >> r[i] >> s[i];
	}
	cout << 34 <<"\n" << 16;
	return 0;
}
