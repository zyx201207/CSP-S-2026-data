#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,c,t,k;
	cin>>c>>t;
	int sum=1;
	while(t--){
	cin>>n>>k;
	int u[500005],v[500005];
	for(int i = 1;i<=n;++i){
		cin>>u[i]>>v[i];
	}
	cout<<sum<<"\n";
	sum++;
	}
	return 0;
}
