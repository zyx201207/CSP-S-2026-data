#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[1000005],zy[1000005],b[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		long long ans = 0;
		cin >> n >> d;
		for(long long i = 1;i <= n;i++){
			for(long long j = i+1;j <= n;j++) b[i][j] = 2e18;
		}
		for(long long i = 1;i <= n;i++) cin >> x[i];
		cout << 0 << '\n';
		/*for(long long i = 1;i <= n;i++){
			long long l = i,r = n,mb = i;
			while(l <= r){
				long long mid = (l+r)/2;
				if(x[mid] <= x[i]+d){
					mb = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			zy[i] = mb;
			for(long long j = i+1;j <= zy[i];j++) b[i][j] = 1;
		}
		for(long long i = 1;i <= n;i++){
			long long d = zy[i];
			while(d < n){
				long long dd = zy[d];
				if(dd == d) break;
				for(long long j = d+1;j <= dd;j++) b[i][j] = b[i][d]+1;
				d = dd;
			}
		}
		for(long long i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				long long xd = i,d = zy[xd],dd = zy[d],c = 1,nw = zy[i];
			//	cout << 114514 << " " << i << endl;
				while(d < n){ 
			//		cout << xd << " " << d << " " << dd << endl;
					dd = zy[d];
					d = zy[xd];
					if(dd == d || d == xd) break;
					long long l = xd,r = d-1,mb = d;
					while(l <= r){
						long long mid = (l+r)/2;
			//			cout << mid << " " << b[mid][dd] << endl;
						if(b[mid][dd] == b[d][dd]){
							mb = mid;
							r = mid-1;
						}
						else l = mid+1;
					}
					c *= (d-mb+1);
					if(c > 2) break;
					nw = zy[d];
					xd = d;
					d = dd;
				}
			//	cout << ans << endl;
			//	cout << nw << " " << zy[i] << endl;
				if(c == 2)ans += 1;
			}
			//cout << ans << '\n';	
		}
		cout << ans << '\n';*/
	}
	return 0;		
}
	
	
