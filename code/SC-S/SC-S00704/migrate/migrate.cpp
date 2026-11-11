#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN = 2e6 + 5;
int c,t,n;
ll d,x[MAXN],f[MAXN],cnt[MAXN],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	 
	cin >> c >> t;
	while (t--){
		ans = 0;
		cin >> n >> d;
		for (int i = 1;i<=n;i++) cin >> x[i];
		for (int i = 1;i<=n;i++){
			memset(f,0x3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			f[i] = 0;
			
			for (int j = i;j<=n;j++){
				int k = j-1;
				for (;k>=i && x[j] - x[k] <= d;k--){
					if (f[k] + 1 < f[j]){
						cnt[j] = 1;
						f[j] = f[k] + 1;
					}
					else if (f[k] + 1 == f[j]) cnt[j]++;
				}
				if (cnt[j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
}