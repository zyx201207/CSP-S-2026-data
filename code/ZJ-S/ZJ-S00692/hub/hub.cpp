#include<iostream>
using namespace std;
int t,c,n,k,x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(;t--;){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>x>>y;
		cout<<(n-k+3)/4<<'\n';
	}
	return 0;
}
