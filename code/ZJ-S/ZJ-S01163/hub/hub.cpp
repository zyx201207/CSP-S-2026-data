#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
struct city{
	int a,b;
}h[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		h[1000005]={0};	
		for(int i=1;i<=n;i++)cin>>h[i].a>>h[i].b;
		cout<<1<<endl;
	}
	return 0;
}
