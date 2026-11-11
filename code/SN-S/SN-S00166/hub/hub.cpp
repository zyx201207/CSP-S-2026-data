#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,k;
int a,b;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>a>>b;
		cout<<((n+1)/2-k)/4+1<<"\n";
	}
	return 0;
}
