#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int a[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		int f=d/(a[2]-a[1]);
		if(f==1){
			cout<<0;
			continue;
		}
		for(int i=int(f*1.5);i<=(a[n]-a[i])/(a[2]-a[1]);i+=f){
			for(int j=1;j+i<=n;j++){
				ans++;
			}
		}
		cout<<ans<<"\n"
	}
}