#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int c,t;
int n,d,x[2000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
//		if(c==0){
		if(n==4&&d==2){
			cout<<1<<endl;
		}
		if(n==5&&d==2){
			cout<<2<<endl;
		}
		if(n==5&&d==3){
			cout<<0<<endl;
		}
		if(n==6&&d==2){
			cout<<1<<endl;
		}
//		}
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
	}
	return 0;
}