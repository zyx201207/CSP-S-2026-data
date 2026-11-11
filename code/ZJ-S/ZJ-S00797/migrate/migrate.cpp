#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,t,n,d,a[N],step;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		step=d/(a[2]-a[1]);
		for(int i=1;i<=n;i++){
			int l=i+step+1;
			if(l>=n)continue;
			cnt+=n-l+1;
			int x=(l)%step;
			int y=l+x;
			cnt-=(n-y+1)/step;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
