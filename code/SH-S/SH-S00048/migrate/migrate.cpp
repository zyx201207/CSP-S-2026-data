#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=j){
						cnt++;
					}
				}
				if(cnt==2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
