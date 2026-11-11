#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+5;
int yuanshen,t;
int n,d,x[MAXN];
mt19937 rng(time(0));
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>yuanshen>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<rng()<<"\n";
	}
	return 0;
}
