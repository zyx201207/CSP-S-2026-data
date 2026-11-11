#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
int a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		if(d/(a[2]-a[1])==2){
			cout<<n-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}
    return 0;
}