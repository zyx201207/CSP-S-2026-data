#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e6+5;
int C,t,n,d,a[N],c[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			c[i]=a[i]-a[i-1];
		}
		bool flg=1;
		for(int i=2;i<n;++i)if(c[i]!=c[i+1])flg=0;
		if(flg){//special A
			int x=d/c[2];
			if(x<=1||n<2*x){
				cout<<"0\n";
				continue;
			}
			cout<<n-2*x+1<<"\n";
		}
	}
}
