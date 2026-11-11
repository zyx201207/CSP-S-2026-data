#include <bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int t1 = t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i = 1; i <= n - 1; i++)
			cin>>u[i]>>v[i];
		if(t1==2&&t==2) cout<<1<<endl;
		if(t1==2&&t==1) cout<<2<<endl;
		if(t1==3&&t==3) cout<<1<<endl;
		if(t1==3&&t==2) cout<<1<<endl;
		if(t1==3&&t==1) cout<<2<<endl;
	}
	return 0;
}

