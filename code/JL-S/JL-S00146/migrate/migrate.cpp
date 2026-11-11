#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d,ans=0;
		cin>>n>>d;
		vector<ll> x(n);
		for(int i=0;i<n;i++)
			cin>>x[i];
		if(n==1||n==2){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n-2;i++){
			for(int j=i+2;j<n;j++){
				if(x[j]-x[i]<=d)
					continue;
				ll cnt=0,step=j-i;
				for(int k=i+1;k<=j-1;k++){
					if(x[k]-x[i]<=d){
						if(x[j]-x[k]<=d){
							if(step>2){
								cnt=0;
								step=2;
							}
							if(step==2){
								cnt++;
							}
						}else{
							for(int kk=k+1;kk<=j-1;kk++){
								if(x[kk]-x[i]<=d&&x[j]-x[kk]<=d){
									if(step>3){
										cnt=1;
										step=3;
									}
									if(step==3){
										cnt++;
									}
								}
							}
						}
					}else
						break;
				}
				if(cnt==2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
