#include<bits/stdc++.h>
using namespace std;
int c,t;
int u[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int mx=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y; 
			if(i==1){
				u[x]=1;
				u[y]=u[x]+1;
			}
			else{
				u[y]=u[x]+1;
			}
			mx=max(mx,u[y]);
		}
		cout<<max(((n+mx)/2-k)/2,1)<<endl;
	}
	return 0;
}