#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[100010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++)cin>>a[i]>>a[i];
		cout<<a[n/2]<<'\n';
	}
	return 0;
} 
