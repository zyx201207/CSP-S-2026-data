#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			long long k=x[2]-x[1];
			long long g=d/k;
			if(g<2||g*2>=d-1)cout<<0<<endl;
			else{
				long long ans=0;
				for(int i=3;i<=n;i++){
					if(i%g==0)continue;
					ans+=n-i;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
