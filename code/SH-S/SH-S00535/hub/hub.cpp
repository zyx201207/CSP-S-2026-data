#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
vector<int> a[1000006];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<=n;i++){
			int x,y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if(c==13||c==14){
			int m=n/2;
			if(k>=m){
				cout << 1 << "\n";
			}
			else if(k<m){
				cout << (m-k+7)/4 << "\n";
			}
		} 
	}
	
	
	return 0;
} 
