#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
int c,t;
cin>>c>>t;
if(c == 13||c == 14){
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n][2];
		for(int i=1;i<n;i++){
			cin>>a[i][0]>>a[i][1];
		}
		if(n%(k+1) == 0){
			cout<<n/(k+1)<<endl;
		}else {
			cout<<n/(k+1)+1<<endl;
		}
	}
}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
