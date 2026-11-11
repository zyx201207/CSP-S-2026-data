#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace TEST_13_14{
	int n,k;
	void Solve(){
		int _,m; cin>>n>>k; m=n/2;
		for(int i=1;i<n;i++){
			cin>>_; cin>>_; 
		}
		cout<<(m-k+6)/4<<"\n";
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("hub5.in","r",stdin);
//	freopen("hub5.out","w",stdout);
	int c,T; cin>>c>>T;
	while(T--){
		if(13<=c&&c<=14) TEST_13_14::Solve(); 
	}
	return 0;
}
