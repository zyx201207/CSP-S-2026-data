#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T,n,k;
vector<int> G[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<=n;i++){
			cin>>u>>v;
			
		}
		cout<<ceil(((int)n/2)/2)-k/4<<'\n';
	}
	return 0;
}

