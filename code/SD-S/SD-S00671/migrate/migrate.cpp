#include<bits/stdc++.h>
using namespace std;
#define N 100100
#define endl "\n"
#define mod 998244353
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			vector<int>a(n+10);
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int use=a[2]-a[1]+1;
			int l=d/use;
			long long ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(n-(i+l),0);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//migrate
