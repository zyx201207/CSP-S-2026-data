#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<rand()%t*rand()%t<<'\n';
	}
	return 0;
}