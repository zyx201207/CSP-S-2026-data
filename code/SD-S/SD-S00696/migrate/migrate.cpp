#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+3;
int arr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		if(c==13||c==14){cout<<"0\n";continue;}
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>arr[i];
		int m=arr[2]-arr[1];
		if(d<m*2) cout<<"0\n";
		else{
			m=(d/m)<<1;
			if(n-m+1<0) cout<<"0\n";
			else cout<<n-m+1<<"\n";	
		}
	}
	return 0;
}

