#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define ll long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d,x;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>x;
		cout<<(n-1)*(n-2)/2<<"\n";
	}
	return 0;
}