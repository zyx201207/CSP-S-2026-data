#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,u[2000010],v[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;++i)cin>>u[i]>>v[i];
		cout<<min(n,m)-1<<"\n";
	}
	return 0;
}
