#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int x,y;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x>>y;
		}
		cout<<abs(n-3*m)<<'\n';
	}
	return 0;
} 
