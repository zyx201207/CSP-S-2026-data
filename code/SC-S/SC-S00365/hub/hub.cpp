#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=2e6+2;
int c,t,n,d,xi[mxn];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>xi[i];
		for(int i=1;i<=n;i++){
			int pos=upper_bound(xi+1,xi+1+n,xi[i]+d)-xi-1;
		}
		cout<<0<<endl;
	}
}