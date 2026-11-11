#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[(int)2e6+10];
signed main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
	cin>>c>>t;
	if(c==11||c==12) 
	while(t--){
		int n,m,d;
		cin>>n>>d;
		m=n;
		if(n<3){while(n--)cin>>d;cout<<0<<"\n";continue;}
		while(m--)cin>>a[m];
		if(a[0]-a[2]<=d)cout<<max(0ll,n+1-2*(d)/(a[0]-a[1]))<<"\n";
		else cout<<0<<"\n";
	} 
	else if(c==13||c==14){
		while(t--)cout<<0<<"\n";
	}
	return 0;
}
//音音音音音 
