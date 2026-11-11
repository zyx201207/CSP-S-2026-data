#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,l[505][505],r[500005];
vector<long long> n[500005],m[500005],x[505],y[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> a >> a >> b >> c >> d;
	for(long long i=1;i<=b;i++){
		cin >> r[i];
	}
	for(long long i=1;i<=a;i++){
		cin >> e;
		for(long long j=1;j<=e;j++){
			long long xx,yy;
			cin >> xx >> yy;
			x[i].push_back(xx);
			y[i].push_back(yy);
			n[xx].push_back(i);
			m[xx].push_back(yy);
		}
	}
	for(long long i=1;i<=a;i++){
		for(long long j=1;j<=a;j++){
			if(i!=j){
				l[i][j]=1e18;
			}
		}
	}
	for(long long i=1;i<=a;i++){
		long long s=x[i].size();
		for(long long jj=0;jj<s;jj++){
			long long j=x[i][jj];
			long long ss=n[j].size();
			for(long long k=0;k<ss;k++){
				l[i][n[j][k]]=min(l[i][n[j][k]],y[i][jj]+m[j][k]);
				l[n[j][k]][i]=min(l[n[j][k]][i],y[i][jj]+m[j][k]);
			}
		}
	}
	for(long long i=1;i<=a;i++){
		for(long long j=1;j<=a;j++){
			for(long long k=1;k<=a;k++){
				if(l[i][k]+l[k][j]<l[i][j]){
					l[i][j]=l[i][k]+l[k][j];
				}
			}
		}
	}
	while(d--){
		long long xx,yy;
		cin >> xx >> yy;
		long long s=n[xx].size(),ans=1e18;
		for(long long i=0;i<s;i++){
			long long ss=n[yy].size();
			for(long long j=0;j<ss;j++){
				ans=min(ans,l[n[xx][i]][n[yy][j]]+m[xx][i]+m[yy][j]);
			}
		}
		cout << ans+r[xx]+r[yy] << "\n";
	}
	return 0;
} 
