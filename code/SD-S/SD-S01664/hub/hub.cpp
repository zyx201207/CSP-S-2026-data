#include<bits/stdc++.h>
using namespace std;
int c;
long long t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,m,x,y,ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			ans+=y-x;
		}
		cout<<ans/(n-1)<<endl;
	}
} 
