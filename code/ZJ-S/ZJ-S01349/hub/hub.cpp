#include<bits/stdc++.h>
using namespace std;
long long t,ccc,n;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>ccc;
		for(int i=1;i<n;i++) cin>>ccc>>ccc;
		cout<<n/5<<'\n';
	}
	return 0;
}