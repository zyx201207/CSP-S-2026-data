#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2000010;
int p,t,n;
long long d,a[N],c[N],s;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>p>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int t=a[2]-a[1];
		if(t>=d){
			cout<<ans<<endl;
		}
		else if(3*t<=d){
			cout<<ans<<endl;
		}
		else{
			cout<<n-3;
		}
	}
	return 0;
}
//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
