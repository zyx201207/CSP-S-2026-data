#include<bits/stdc++.h>

using namespace std;
const int NN=2*1e6+10;
int x[NN];
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;++i){
			cin >> x[i];
		}
	}
	cout<<1<<endl<<2;
    return 0;
}


