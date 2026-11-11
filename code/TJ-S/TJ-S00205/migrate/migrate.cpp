#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000006],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]>d and a[i+2]-a[i]<=d and a[i+3]-a[i+1]<=d){
				ans++;
			}
			if(i>=4 and a[i]-a[i-1]==d) ans++;
			if(i<=n-4 and a[i+4]-a[i+3]==d) ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
