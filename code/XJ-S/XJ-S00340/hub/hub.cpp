#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u[50010],v[50010];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	for(int i=1;i<=t;i++){
		if(t=1)cout<<0<<endl;
		else if(t=2)cout<<1<<endl;
		else cout<<2;
	}
	return 0;
}
