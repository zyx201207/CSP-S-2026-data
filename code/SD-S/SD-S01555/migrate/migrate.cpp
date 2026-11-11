#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
long long is[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d,ans = 0;
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >> is[i];
		}
		for(int i = 1;i<=n;i++){
			for(int j = i;j<=n;j++){
				if((is[j]+1-is[i])/2>=d) ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
