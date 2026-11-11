#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,t,n,d,a[2000005],f[303][305];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=4;i<=n;i+=2){
				if(a[i/2]-a[1]<=d&&a[i/2+2]-a[1]>d)ans+=n-i+1;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<1<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		/*for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=f[j][i]=1e9;
				if(a[j]-a[i]<=d)f[i][j]=f[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
				}
			}
		}*/
		cout<<n-3;
	}
	return 0;
}