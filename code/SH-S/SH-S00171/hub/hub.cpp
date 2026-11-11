#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,j=0;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<++j<<endl;
	}
	return 0;
}
