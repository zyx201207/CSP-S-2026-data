#include<bits/stdc++.h>
using namespace std;
signed main(){
	srand(time(0));
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%(int)1e6<<'\n';
	}
	return 0;
}
