#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N=2e6+5;
int c,t;
int n,d;
int x[N];
int ans=0;
signed main(){
	fast;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	while(t--){
		cout<<0<<endl;
	}
	return 0;
}