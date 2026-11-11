#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(a[j]-a[i]<=d) continue;
				int r=upper_bound(a+i,a+j+1,a[i]+d)-a-1,l=lower_bound(a+i,a+j+1,a[j]-d)-a;
				if(r-l<1) break;
				if(r-l==1) cnt++;
			}
		}cout<<cnt<<'\n';
	}return 0;
}
