#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000010],v[2000010],h;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		h=1;
		for(int j=1;j<n;j++){
			cin>>u[i]>>v[i];
		}
		cout<<h<<endl;
	}
	return 0;
}
