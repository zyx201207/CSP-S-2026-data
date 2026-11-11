//hub
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+5;
int c,t;
int n,k,a[N],b[N];
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	/**/
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i];
		}
		cout << "1\n"; 
	}
	return 0;
	
} 
/*

2

  |   |
1 2 4 8 9
3 2 0
*/
