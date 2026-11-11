#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,di,x[2000005];
vector<int> e[200005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
    	cin>>n>>di;
    	for(int i=1;i<=n;i++)
    	  cin>>x[i];
    	int mx=di/(x[2]-x[1]);
		cout<<n-mx-2<<'\n';
	}
}
