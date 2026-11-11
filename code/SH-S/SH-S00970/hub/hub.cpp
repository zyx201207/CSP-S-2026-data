#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,t,a;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while (t--){
		cin>>n>>k;
		for (int i=1;i<n;i++){
			cin>>a>>a;
		}cout<<(long long)((((n+3)/2-k)/4.0)+0.99)<<"\n";
	}return 0;
}
