#include<bits/stdc++.h>
using namespace std;
long long n,k,u,v,ans,c,t;
vector<long long> a[500005];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;	
		}
		if(k>=n/2){
			cout<<1<<endl;
		}
		else{
			if((n/2)%2==0){
				ans=(n/2)/2+1;
				for(int i=2;i<n;i++){
					if(i%2==0){
						ans--;
					}
					if(i==k){
						cout<<ans/2<<endl;
						break;
					}
				}
			}
			else{
				ans=(n/2)/2+1;
				for(int i=2;i<n;i++){
					if(i%2==1){
						ans--;
					}
					if(i==k){
						cout<<ans/2<<endl;
						break;
					}
				}
			}
		
		}
	}
	return 0;
}
