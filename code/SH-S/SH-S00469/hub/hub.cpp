#include<bits/stdc++.h>
using namespace std;
void each(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		ans=u+v/2; 
	}
	cout<<abs(ans-n+k);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		each();
	}
	return 0; 
} 
