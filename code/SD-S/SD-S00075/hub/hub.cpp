#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		int m=(n-1)/2;
		int ans=0;
		if(k==n){
			ans=0;
		}
		else if(k<n&&k>=m-2){
			ans=1;
		}
		else{
			if((m+2-k)%4==0){
				ans=(m+2-k)/4;
			}	
			else{
				ans=(m+2-k)/4;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
