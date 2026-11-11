#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=2e6+10;
int c,T,p[N],dp[N],s[N],t[N],ans=0;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>c>>T;
	while(T--){
		int n,d;cin>>n>>d;
		ans=0;
		for (int i=1;i<=n;i++)cin>>p[i];
		if (n<4){
			cout<<0<<endl;continue;
		}
		sort(p+1,p+n+1);
		for (int i=4;i<=n;i++){
			int s=p[i]-d;
			int L=lower_bound(p+1,p+i,s)-p;
//			cout<<i<<'-'<<L<<endl;
			if (L==i)continue;
			for (int j=L;j<i-1;j++){
				int xl=lower_bound(p+1,p+L,p[j]-d)-p;
				if (p[xl]==p[i]-2*d)ans--;
//				cout<<j<<":"<<xl<<endl;
				ans+=L-xl;
			}
//			cout<<ans<<endl<<endl;
			int xl=lower_bound(p+1,p+i-1,p[i-1]-d)-p;
			if (xl>=i-2)continue;
//			cout<<"hjjhg"<<"---"<<i-2-xl<<endl;
			ans+=i-2-xl;
//			cout<<i<<"---"<<ans<<endl;
		}
		cout<<ans<<endl;
	}	
	return 0;
}
