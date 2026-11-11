#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],ans;
signed main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>x[i];
		for(int i=3;i<n;i++){
			if(abs(x[i]-x[0])>d){
				cout<<n-i<<'\n';
				break;
			}
			else {
				cout<<0<<'\n';
				break;
			}
		}
	}
	return 0;
}
