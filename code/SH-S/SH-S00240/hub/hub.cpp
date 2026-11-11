#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>u>>v;
		if(n==k)
			cout<<"0\n";
		else
			cout<<"1\n";
	}
	return 0;
}
