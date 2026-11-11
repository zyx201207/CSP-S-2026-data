#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10;
int c,T;
int n,d,x;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(n>=20){
			int gc=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				gc=a[i]-a[i-1];
			}
			int ans=(n-(2*(d/gc+1)-2)+1);
			if(d<=gc||ans<0) cout<<0<<"\n";
			else cout<<ans<<"\n";
		}
	}
} 
