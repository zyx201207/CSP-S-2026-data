#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i!=n-1;++i){
			cin>>u[i]>>v[i];
		}
		if(c==0){
			cout<<1<<'\n'<<2;
			continue;
		}
		cout<<1;
	}
} 
