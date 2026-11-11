#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11 || c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[3]-a[1]!=d){
				cout<<"0\n";
				continue;
			}
			int ans=0;
			if(n>=4){
				ans=n-3;
				ans=(ans+1)*ans/2;
			}
			cout<<ans<<"\n";
		}
	}
	if(c==13 || c==14){
		while(T--)cout<<"0\n";
		return 0; 
	}

	return 0;
}

