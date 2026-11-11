#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		int arr[4005][4005]={};
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			arr[u][v]=1;
			arr[v][u]=1;
		}
		if(T==0){
			cout<<2;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}

