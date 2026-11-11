#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w[510000];
int main(){//chai
	////////   ////////        |             |
	//    //   //   //         |             |
	//  //     // //      =====+=====   =====+=====
	/////      ///             |             |
	//  //     //              |             |
	//    //   //              |             |
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int x,l;
	for(int i=1;i<=m;i++){
		
		cin>>x;
		for(int j=1;j<=x;j++) cin>>l;
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<(u*v+x%l*c)%q<<endl;
	}
	return 0;
}
                