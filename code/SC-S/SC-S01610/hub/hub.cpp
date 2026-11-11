#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(n==k)
			cout<<0<<'\n';
		else
			cout<<1<<'\n';
	}
	return 0;
}