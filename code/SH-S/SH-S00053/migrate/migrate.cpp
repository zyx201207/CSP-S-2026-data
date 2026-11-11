#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 2e6;
const ll MAXX = 1e8;

int c,t;
int n;
ll d,x[MAXN],ret[MAXX];
void solve(int s,int e,ll cnt){
	if(x[e] - x[s] <= d){
		cnt += x[e] - x[s];
		ret[cnt]++;
		return;
	}
	for(int i = s + 1;x[i] - x[s] <= d;i++){
		int cc = cnt + x[i] - x[s];
		solve(i,e,cc);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		memset(ret,0,sizeof ret);
		for(int s = 1;s <= n;s++){
			for(int e = s + 1;e <= n;e++){
				solve(s,e,0);
				for(int i = 1;i <= MAXX;i++){
					if(ret[i] != 0){
						if(ret[i] == 2){
							ans++;
						}
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
