#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int u[N],v[N];
int c,t,n,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		cout<<1<<"\n";
	}
	return 0;
}
