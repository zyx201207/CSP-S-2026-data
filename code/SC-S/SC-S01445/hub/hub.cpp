#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define first fi
#define second se
const int N=1e6+10;
int c,T,n,k;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<n-1<<'\n';
	}
	return 0;
} 