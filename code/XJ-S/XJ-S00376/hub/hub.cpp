#include<bits/stdc++.h>
using namespace std;
int c,t,pa[1000005];
int find(int x){
	if(x!=pa[x]){
		pa[x]=find(pa[x]);
	}
	return pa[x];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=1 ; i<=1000005 ; i++){
		pa[i]=i;
	}
	cin >> c >> t;
	while(t--){
		for(int i=1 ; i<n ; i++){
		    int u,v;
		    cin >> u >> v;
		    pa[find(u)]=find(v);
	    }
	    int sum=0;
	    for(int i=1 ; i<=n ; i++){
	    	if(pa[i]==n){
	    		sum++;
			}
		}
		if(sum==2){
			cout << "1" << endl; 
		}
	}
	return 0;
}
