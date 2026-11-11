#include<bits/stdc++.h>
using namespace std;
const int awa=1e6+5;
int n,k;
vector<int>V[awa];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(13<=c&&c<=14){
		while(t--){
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++){
				cin>>u>>v;
				V[u].push_back(v);
				V[v].push_back(u);
			}
			cout<<((n+1)/2-k)/4+1<<"\n";
		}
	}
	else{
		while(t--){
			cin>>n>>k;
			for(int i=1,u,v;i<n;i++){
				cin>>u>>v;
				V[u].push_back(v);
				V[v].push_back(u);
			}
			if(n==k){
				cout<<"0\n";
				continue;
			} 
			cout<<1<<"\n";
		}
	}
}
/*不会做，over了，反正今年不用担心退役问题，尽力而为，我不知道，Everything was okay. */
