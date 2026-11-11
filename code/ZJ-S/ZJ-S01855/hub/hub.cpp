#include<bits/stdc++.h>
using namespace std;
int c,ttt;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>ttt;
	while(ttt--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>c>>c;
		cout<<(n-k+2)/3<<"\n";
	}
	return 0;
}
