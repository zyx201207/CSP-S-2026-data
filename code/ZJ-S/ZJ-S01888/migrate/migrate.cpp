#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,t;
int x[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		cnt=(n/d-1)*(d-1)+(n%d);
		cout<<cnt<<"\n";
	}
	
	
	
	
	return 0;
}