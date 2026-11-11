#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	srand(time(0));
	while(t--){
		int n,k;
		cin>>n;
		cout<<(rand()%n+1)<<endl;
	}
	return 0;
}
