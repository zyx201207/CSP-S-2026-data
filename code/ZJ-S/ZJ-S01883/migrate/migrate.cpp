#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int MAXN=2000010;

int c,t,n,d;
int x[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		if (n==1){
			cout<<0<<endl;
			continue;
		}
		int k=x[2]-x[1];
		cout<<d%k<<endl;
	}
	return 0;
}

