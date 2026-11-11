#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		int cnt = 0;
		for(int i = 1;i<n;i++){
			for(int j = 1;j<=n;j++){
				if(a[j]-a[i]>m){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
		