#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int t=1e9;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
			t=min(t,u[i]);
		}
		cout<<t<<endl;
	}
	return 0;
}