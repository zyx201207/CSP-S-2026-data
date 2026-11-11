#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define ll long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k,x,y;
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>x>>y;
		if(k>=n)cout<<"0\n";
		else cout<<(n/2-k)/2+1<<"\n";
	}
	return 0;
}