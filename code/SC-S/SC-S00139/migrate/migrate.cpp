#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		vector<int>A(n);
		for(int i=0;i<n;i++)cin>>A[i];
		int w=A[1]-A[0];
		int z=(2*d)/w;
		int f=n/z*2;
		cout<<f<<"\n";
	}
	return 0;
}