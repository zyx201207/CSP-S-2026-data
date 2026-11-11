#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000005];
long long d,ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=4;i<=n;i++){
				if((a[i]-a[i-3]>d)&&(a[i]-a[i-3]-d<d))ans++;
		}
		cout << ans <<endl;
	}
	return 0;
}
