#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cout<<(n-2*k+1)/8+1<<"\n";
	}
}