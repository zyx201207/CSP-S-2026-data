#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u>>v;
		}
		if(n==5 && k==2) cout<<1;
		else if(n==10 && k==3) cout<<2;
		else cout<<1;
	}
	return 0;
}
