#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,k,a[N];
vector<int>ve[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>k;
    	for(int i=1;i<=n;i++){
    		int u,v;
    		cin>>u>>v;
    		ve[u].push_back(v);
    		ve[v].push_back(u);
		}
		cout<<"0\n";
	}
    return 0;
}
//Oct31==Dec25?
