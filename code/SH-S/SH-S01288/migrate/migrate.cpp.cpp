#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	int c,t,s; 
	cin>>c>>t; 
	for(int i=1; i<=t; i++){
		int n,d,x[200005],ans=0; 
		cin>>n>>d; 
		for(int j=1; j<=n; j++){
			cin>>x[j]; 
		}
		for(int j=4; j<=n; j++){
			if(d>=x[j-2]-x[j-3] && d>=x[j-1]-x[j-3] && d<x[j]-x[j-3] && d>=x[j]-x[j-2] && d>=x[j]-x[j-1]) {
				ans+=1; 
				for(int k=j-4; k>0; k--){
					if(d>=x[k]-x[k-1] && d<x[k+1]-x[k-1]) ans++; 
					else break; 
				}
				for(int k=j; k<=n; k++){
					if(d>=x[k+1]-x[k] && d<x[k+1]-x[k-1]) ans++; 
					else break; 
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0; 
}
