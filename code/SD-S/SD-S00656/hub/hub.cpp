#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int> e[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>k;
    	for(int i=1;i<n;i++){
    		cin>>u>>v;
    		e[u].push_back(v);
    		e[v].push_back(u);
		}
		if(c>=13&&c<=14||c==0){
			int m=n/2;
			if(k>=m)cout<<1<<'\n';
			else cout<<(m+1+k)/(k+1)<<'\n';
		}
	}
	return 0;
}

