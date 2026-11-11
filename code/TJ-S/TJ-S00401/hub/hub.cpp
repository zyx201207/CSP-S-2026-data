#include <bits/stdc++.h>
using namespace std;
int c,t,n,a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>a;
		for(int i=0;i<n-1;i++)cin>>a>>a;
		cout<<n<<"\n" ;
	}
	return 0;
}
