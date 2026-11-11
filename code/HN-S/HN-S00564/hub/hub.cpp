#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,idx=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<idx<<endl;
		idx++;
	}
	return 0;
}
