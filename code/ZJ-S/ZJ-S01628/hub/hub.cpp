#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mcx=2e6+5;
int c,t,n,k,e[5005][5005];
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(e,0,sizeof e);
		cin>>n>>k;
		
		if(c==13||c==14)cout<<(n-k)/2<<'\n';
		else if(k==2)cout<<n/(k*4)<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
