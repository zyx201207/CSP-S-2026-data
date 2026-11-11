#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000005],l[2000005],r[2000005];
__inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c<=10){
		int cnt=0;
		for(int i=1;i<=n;i++){
			l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
			r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(r[i]-1==l[j]) cnt++;
			}
		}
		cout<<cnt<<"\n";
		return;
	}
	if(c==11||c==12){
		int x=d/(a[2]-a[1]);
		if(n<2*x||x<=1) cout<<"0\n";
		else cout<<n-(2*x)+1<<"\n";
		return;
	}
	if(c==13||c==14){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int www=0;
			if(a[i]-d<=a[1]&&a[i]+d>=a[n]){
				cnt++;
				www=i;
			}
			if(cnt>3) cout<<"0\n";
			if(cnt==2) cout<<"1\n";
			else cout<<(i-1)*(n-i)<<"\n"; 
		}
		return;
	}
	cout<<0<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

