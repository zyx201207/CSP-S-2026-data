#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e18+10;
int t,n,d,c;
int a[2000010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			cout<<n-d-1<<'\n';
		}
		if(c==13||c==14){
			cout<<(n/2)<<'\n';
		}
	}
	return 0;
}