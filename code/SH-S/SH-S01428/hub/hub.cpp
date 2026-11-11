#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		int m=n/2;
		if(k==n){
			cout<<0<<endl;
			continue;
		}else{
			if(m<=k){
				cout<<1<<endl;
			}else{
				m/=2;
				k/=2;
				if(m%2==0&&k%2==0){
					cout<<m/2-k/2+1<<endl;
				}else if(m%2==0&&k%2==1){
					cout<<m/2-k/2+1<<endl;
				}else if(m%2==1&&k%2==0){
					cout<<m/2-k/2+2<<endl;
				}else{
					cout<<m/2-k/2+1<<endl;
				}
			}
		}
	} 
	return 0;
}
