#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int c,q,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>q;
	while(q--){
		int n,m,f,s=0,f2=1,ans=0;
		cin>>n>>m;
		f=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>m&&i>1){
				f=i;
			}
			if(i==2){
				s=a[i]-a[i-1];
			}
			if(i>2){
				if(a[i]-a[i-1]!=s){
					f2=0;
				}
			}
		}
		int x=0;
		if(f2==1){
			if(m<=s){
				cout<<0<<endl;
				continue;
			}
			cout<<max(n-(m/s)*2+1,x)<<endl;
			continue;
		}
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]<m&&a[i]-a[i-2]>m){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
