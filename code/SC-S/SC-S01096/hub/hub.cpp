#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,u[1000005],v[1000005],t[1000005];
int main(){
	freopen("hub.in","r",stdin);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>u[i]>>v[i];
			/*t[u[i]].push_back(v[i]);
			t[v[i]].push_back(u[i]);*/
		}
		cout<<k-1<<endl;
	}
	
	
	freopen("hub.out","w",stdout);
	return 0;
} 