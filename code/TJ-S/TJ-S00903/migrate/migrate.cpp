#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e6+1,inf = 0x3f3f3f3f3f3f3f3f;
int c,t,n,d,x[N],dist[N],cnt[N];
bool check(){
	int a = x[2]-x[1];
	for(int i = 2;i<=n;++i){
		if(x[i]-x[i-1]!=a){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i<=n;++i){
			cin >> x[i];
		}
		if(n>1&&check()){
			int k = d/(x[2]-x[1]);
			if(k<=1){
				cout << "0\n";
				continue;
			}
			int ans = 0;
			for(int i = 1;i<=n;++i){
				if(i+2*k-1<=n){
					++ans;
				} 
			}
			cout << ans << '\n';
			continue;
		}else if(n<=500){
			int ans = 0;
			for(int i = 1;i<=n;++i){
				for(int j = i;j<=n;++j){
					dist[j] = inf;
					cnt[j] = 0;
				}
				dist[i] = 0;
				cnt[i] = 1;
				for(int j = i;j<=n;++j){
					for(int k = j+1;k<=n&&x[k]-x[j]<=d;++k){
						if(dist[j]+1<dist[k]){
							dist[k] = dist[j]+1;
							cnt[k] = cnt[j];
						}else if(dist[j]+1 == dist[k]){
							cnt[k]+=cnt[j];
						}
					}
				}
				for(int j = i+1;j<=n;++j){
					if(cnt[j] == 2){
						++ans;
					}
				}
			}
			cout << ans << '\n';
		}else{
			cout << "0\n"; 
		}
	}
	return 0;
}
