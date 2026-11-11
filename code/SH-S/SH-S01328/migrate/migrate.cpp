#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MAXN 305

int c, t;
int n, d;
int x[MAXN];
int dp[MAXN][MAXN][2];


signed small(){
	for(int _=0; _<t; ++_){
		cin >> n >> d;
		int midx;
		for(midx=1; midx<=n; midx++){
			cin >> x[midx];
		}
		--midx;
		
		int ans = 0;
		for(int sti=1; sti<=midx-3; ++sti){
			for(int eni=sti; eni<=midx; ++eni){
				if(eni == sti){
					dp[sti][eni][0] = 0;
					dp[sti][eni][1] = 1;
					continue;
				}
				
//				cout << "at  " << sti << "," << eni << endl;
				dp[sti][eni][0] = -1;
				for(int enj=sti; enj<eni; ++enj){
//					cout << "chk " << sti << "," << enj << " ";
					if(x[eni] - x[enj] > d) {
//						cout << endl;
						continue;
					}
					int enlen = dp[sti][enj][0] + 1;
//					cout << enlen << "."; 
					if(dp[sti][eni][0] == -1 || dp[sti][eni][0] > enlen){
						dp[sti][eni][0] = enlen;
						dp[sti][eni][1] = dp[sti][enj][1];
//						cout << dp[sti][enj][1] << "stn";
					}
					else if(dp[sti][eni][0] == enlen){
						dp[sti][eni][1] += dp[sti][enj][0];
//						cout << dp[sti][enj][1];
					}
//					cout << "\n";
				}
				if(dp[sti][eni][1] == 2) ++ans;
//				cout << sti << "," << eni << ": " << dp[sti][eni][0] << "."
//				<< dp[sti][eni][1] << "\n" << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

signed sp_a(){
	for(int _=0; _<t; ++_){
		cin >> n >> d;
		int a1, a2;
		cin >> a1 >> a2;
		int __;
		for(int i=3; i<=n; i++){
			scanf("%d", &__);
		}
		int l = a2-a1;
		
//		cout << n << " " << d << " " << l << " ";
		
		if(d<2*l) cout << 0 <<endl;
		else {
			int ans = n - d / l * 2 + 1;
			cout << (ans>0 ? ans : 0) << endl;
		}
	}
	
	return 0;
}


signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	switch(c){
		case 1: case 2: case 3: case 4: case 5: case 6:
			return small();
		case 11: case 12:
			return sp_a();
		default:
			cout << "WTF?";
			return 0;
	}
}

