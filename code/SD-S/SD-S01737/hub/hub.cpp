#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>T;
	while (T--){
		cin>>n>>k;
		for (int i = 1,u,v;i < n;i++){
			cin>>u>>v;
		}
		int m = (n-1)/2;
		int x = m+2-k;
		x = x/2+(x&1);
		cout<<x/2+(x&1)<<'\n';
	}
	
	return 0;
}
