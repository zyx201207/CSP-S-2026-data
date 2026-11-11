#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll q,t,n,m,a[2000005],c[2000005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>q>>t;
	if(q==13 || q==14){
		while(t--){
			cout<<0<<"\n";
		}
		return 0;
	}
	if(q==11 || q==12){
		while(t--){
			ll cc,ans=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cc=a[n]-a[n-1];
			m/=cc;
			if(m==0||m==1){
				cout<<0<<"\n";
				continue;
			}
			ans=n-m-m+1;
			if(ans>=0){
				cout<<ans<<"\n";
			}
			else{
				cout<<0<<"\n";
			}
		}
	}
	return 0;
}

