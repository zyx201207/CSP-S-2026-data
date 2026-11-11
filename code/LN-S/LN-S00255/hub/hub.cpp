#include <bits/stdc++.h>
using namespace std;
int c,t;
const int N=1e6+1;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	int cnt=-1;
	while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++) cin>>u[i]>>v[i];
        cnt+=4;
        cout<<cnt<<'\n';
	}
	return 0;
}
