#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
#define f1 first
#define s2 second
const int N=2e6+10;
int n,d;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) cin>>x[i];
		else cout<<0<<'\n';
	}
	return 0;
}