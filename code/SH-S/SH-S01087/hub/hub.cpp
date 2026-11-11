#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=1e6+10;
int n,k;
inline void MAIN(){
	cin>>n>>k;
	if(c>=13&&c<=14){
		if(k>=n){
			cout<<"0\n";
			return;
		}
		int m=n/2;
		cout<<(m-k+3)/4+1<<'\n';
		return;
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) MAIN();
	return 0;
}
