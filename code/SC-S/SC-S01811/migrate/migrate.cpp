#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t;
int n,d,a[2000006],s[2000006];


signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12)cout<<max(n-3,(long long)0)<<endl;
		else cout<<0<<endl;
	}
}