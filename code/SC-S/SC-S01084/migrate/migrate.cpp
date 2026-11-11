#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[1000000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	int ans=0;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=2;j<=n;j++){
			if((x[j]-x[1])%d==0 && j+d-1<=n){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}