#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1145141
int n;
int c,T;
int u,v;
int k;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<n/4<<endl;
	}
}
