#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=2e6+51;
int c,t;
int n;
ll d;
ll q[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12) {
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>q[i];
			}
			ll cha=d/(q[2]-q[1]);
			if(n>=2*cha-1&&cha>=2) {
				cout<<n-(2*cha-1);
			}
			else cout<<0;
			
			cout<<endl;
		} 
	}
	return 0;
}


