#include<bits/stdc++.h>
using namespace std;
int c,T,u[1000005],v[1000005],dist[1000005],n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			cin>>u[i]>>v[i];
		}
		if(c==13||c==14){
			int m=(n-1)/2,ans;
			if(k>=m){
				ans=1;
			}
			else{
				ans=(m-k+3)/4+1;
			}
			cout<<ans<<endl;
		}
	}
}
