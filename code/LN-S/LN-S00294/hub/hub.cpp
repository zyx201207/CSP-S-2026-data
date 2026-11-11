#include<bits/stdc++.h>
using namespace std;
int n,k,c,t;
int cnt;
int p[2000005];
struct hu{
	int u,v;
}g[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cnt=n+k;
		cout<<cnt<<endl;
	}
	return 0;
}
