#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long m,a[N],ans;
int c,t,n,s[N],k[N];
bool flag;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			s[i] = k[i] = 0;
		}
		for(int i = 4;i <= n;i++){
			if(a[i] - a[i - 3] > m && a[i] - a[i - 2] <= m){
				s[i]++;
				k[i - 3]++;
			}
		}
		for(int i = 1;i <= n;i++){
			s[i] += s[i - 1];
			k[i] += k[i - 1];
		}
		for(int i = 1;i <= n - 3;i++){
			for(int j = i + 3;j <= n;j++){
				flag = 1;
				for(int l = i + 1;l <= j;l++){
					if(a[l] - a[l - 1] > m){
						flag = 0;
						break;
					}
				}
				if(!flag){
					continue;
				}
				if(s[j] - k[i - 1] == 1){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
