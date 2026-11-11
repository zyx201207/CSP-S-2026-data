#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d;
int x[2000100];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==13||c==14){
			int cnt;
			for(i=2;i<=n;i++){
				if(d<(x[i]-x[1])){
					break;
				}
				d-=(x[i]-[1]);
				cnt=i;
			}
			cout<<(i-1)*(n-i)<<"\n";
		}
	}
	return 0;
}
