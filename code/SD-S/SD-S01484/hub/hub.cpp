#include<bits/stdc++.h>
using namespace std;
int u[10010],v[10010],c,t,n,k,cnt;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<=n;i++){
			cnt+=u[i]-v[i];
		}
		cout<<cnt;
	}
	return 0;
}

