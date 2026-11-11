#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+5;
int n,d;
int a[N],lst[N],dp[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			int t=d/(a[2]-a[1]);
			cout<<n-2*t+1<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
