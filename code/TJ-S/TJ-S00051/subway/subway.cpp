#include<bits/stdc++.h>
using namespace std;
long long n,m,w[500100],a[510][500010],t[510][500010],k[510],q,ans,d,x[100010],y[100010],c;
long long che(long long x,long long y,long long ma){
	long long mi = 2000000;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=k[i];j++){
			ma = 0;
			if(a[i][j] == x){
				ma += t[i][j] + t[i][3-j];
				x = a[i][3-j];
				while(1){
					for(long long l=i+1;l<=n;l++){
						for(long long z=1;z<=k[l];z++){
							if(a[l][z] == x){
								ma += t[l][z] + t[l][3-z];
								x = a[l][3-z];
								if(x == y)break;
							}
						}
					}
				}
				mi = min(mi,ma);
			}
		}
	}
	return mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(long long Q = 1;Q<=q;Q ++){
		ans = w[x[Q]] + w[y[Q]] + che(x[Q],y[Q],0);
		cout<<ans;
	}
	return 0;
}
