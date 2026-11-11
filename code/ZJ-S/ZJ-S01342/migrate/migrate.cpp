#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,e;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    cin>>e>>_;
    while(_--){
    	int n,m,a[2100001],x;
    	cin>>n>>m;
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    		x=a[i]-a[i-1];
		}
		if(x>m||3*x<=m)cout<<0<<"\n";
    	else cout<<n-3<<"\n";
	}
	return 0;

}
