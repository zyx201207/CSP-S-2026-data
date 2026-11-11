#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl "\n"
int c,t,n,d,a[2000009];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n*d/(a[2]-a[1])/2+1<<endl;
	} 
	return 0;
}
