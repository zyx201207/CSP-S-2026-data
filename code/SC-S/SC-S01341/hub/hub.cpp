#include<bits/stdc++.h>
using namespace std;
long long c,t,k,n,l[100][100],u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>u>>v;
			l[u][v]=l[v][u]=1;
		}
		if(k<=2){
			cout<<k-1<<endl;
		}else{
			cout<<k/4<<endl;
		}
		
	}
	
	return 0;
} 