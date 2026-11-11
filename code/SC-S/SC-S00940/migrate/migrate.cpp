#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,c,t,ans;
int a[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans = 0;
		memset(a,0,sizeof a);
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if(i>3){
				if((a[i]-a[i-1]<=d && a[i]-a[i-2]<=d)&&(a[i]-a[i-3]>d)) ans++;
				
			}
		}
		cout << ans <<"\n";
	}
}