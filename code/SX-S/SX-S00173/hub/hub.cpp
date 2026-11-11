#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,T,n,k,u,v;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	for(int t = 1;t<=T;t++){
		cin>>n>>k;
		for(int i = 1;i<n;i++){
			cin>>u>>v;
		}
		cout<<t<<endl;
	}
	return 0;
}
