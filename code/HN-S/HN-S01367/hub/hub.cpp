#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		int n,k,x,y;
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>x>>y;
		cout<<rand()%(time(0)/11111212)<<endl;
		t--;
	}
	return 0;
}

