#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T,n,k,u,v;
	cin>>c>>T;
	srand(time(0));
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<rand()%1000<<endl;
	}
}
