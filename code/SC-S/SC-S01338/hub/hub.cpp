#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u>>v;
		if(k==n)cout<<0<<"\n";
		else{
			int m=(n+1)/2;
			for(int i=1;i<=m-1;i++){
				int kk=k,u=1;
				k--;
				while(u<m){
					u+=2*i+1;
					kk--;
				}
				if(kk==0){
					if(m-u<=i){
						cout<<i<<"\n";
						break; 
					}else{
						continue;
					}
				}else{
					cout<<i<<"\n";
					break; 
				}
			}
		}
	}
	return 0;
}