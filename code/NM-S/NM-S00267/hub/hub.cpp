#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,x;i<=n;i++)cin>>x>>x;
		cout<<n+k-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
