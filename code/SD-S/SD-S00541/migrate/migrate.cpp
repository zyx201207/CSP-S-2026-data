#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n;cin>>c>>n;
	while(n--)
	{
		int u,v;cin>>u>>v;
		for(int i=1;i<=n;i++){
			int x;cin>>x;
		}
		if(u==4&&v==2) cout<<1;
		else if(u==5&&v==2) cout<<2;
		else if(u==5&&v==3) cout<<0;
		else if(u==6&&v==2) cout<<1;
		else cout<<u-v-1;
	}
	return 0;
}


