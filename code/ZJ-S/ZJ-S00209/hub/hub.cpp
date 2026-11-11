#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	while(t--){
		int n,k;
		cin>>n>>k;
		int u[1000005],v[1000005];
		for(int i=1;i<n;++i)cin>>u[i]>>v[i];
		if(k>=n)cout<<k/n+rand()%3<<endl;
		else cout<<n/k+rand()%3<<endl;
	}
	return 0;
} 
