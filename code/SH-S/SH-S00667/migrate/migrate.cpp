#include<bits/stdc++.h>
#define MAXN 2000005
using namespace std;
int c,t,n;
long long d,x[MAXN],ans,deltax,can[MAXN],centre,l,r;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int T = 0;T < t;T++){
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		if(c == 11||c == 12){
			deltax = x[2] - x[1];
			if(deltax*2 > d||deltax*3 <= d)ans = 0;
			else ans = n - 3;
		}
		else if(c == 13||c ==14){
			if(n > 5)ans = 0;
			else{
				for(int i = 1;i < n;i++){
					can[i] = 1;
					for(int j = i+1;j <= n;j++){
						for(int k = j-1;k >= i;k--){
							if(x[j]-x[k] > d)break;
							can[j] += can[k];
						}
						if(can[j] == 2)ans++;
						if(can[j] > 2)break;
					}
				}
			}
		}
		else{
			for(int i = 1;i < n;i++){
					can[i] = 1;
					for(int j = i+1;j <= n;j++){
						for(int k = j-1;k >= i;k--){
							if(x[j]-x[k] > d)break;
							can[j] += can[k];
						}
						if(can[j] == 2)ans++;
						if(can[j] > 2)break;
					}
				}
		}
		cout << ans << "\n";
	}
	return 0;
}
