#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int n,k;
vector<int> edg[N];
inline void add(int u,int v){
	edg[u].push_back(v);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		if(k==n){
			cout<<"0\n";
			continue;
		}
			int ans=n;
			if(k*2>=n-1){
				cout<<"1\n";
				continue;
			}
			n=(n-1)/2;
			n=(n+1)/2;
			if(n%2==0){
				k/=2;
			}
			else{
				k=(k+1)/2;
			} 
			cout<<(n-k+3)/2<<'\n';
			continue;
		for(int i=1;i<=n;i++) edg[i].clear();
	}
	return 0;
}
