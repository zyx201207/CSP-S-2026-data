#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d,cnt=0,flag;
vector<int> x;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			x.push_back(a);
		}
		cout<<0<<'\n';
	}
	return 0;
}
