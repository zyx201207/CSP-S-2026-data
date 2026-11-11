#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000006],nr[50006][50005],ans;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				int k=j+i-1;
				if(i==3&&a[k]-a[j]+1<=d){
					nr[i][j]=1;
				}else if(nr[i-1][j]==1&&nr[])
			}
		}
	}
	cout<<ans;
	return 0;
}
