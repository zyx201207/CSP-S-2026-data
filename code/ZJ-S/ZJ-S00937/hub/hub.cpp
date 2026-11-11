#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,t,n,k,u,v;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u>>v;
		cout<<(n-k)/4<<"\n";
	}
	return 0;
}
