#include<bits/stdc++.h>
using namespace std;
long long x[2000005]; 
long long d[5005][5005];
long long k[5005][5005];
vector<int> is;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d1;
		cin>>n>>d1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			int ans=0;
			for(int i=4;i<=n;i+=2){
				if(x[i]-x[i/2]<=d1&&x[i]-x[i/2-1]>d1){
					ans+=n-i+1;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=1e9;
				k[i][j]=0;
			}
		}
		for(int i=1;i<=n-1;i++){
			if(x[i+1]-x[i]<=d1){
				d[i][i+1]=1;
				k[i][i+1]=1;
			}
		}
		long long ans=0;
		for(int len=2;len<=n;len++){
			for(int i=1;i+len<=n;i++){
				long long mi=1e9;
				if(x[i+len]-x[i]<=d1){
					d[i][i+len]=1;
					k[i][i+len]=1;
					continue;
				}
				for(int j=i+1;j<=i+len-1;j++){
					mi=min(mi,d[i][j]+d[j][i+len]);
				}
				d[i][i+len]=mi;
				int sum=0;
				for(int j=1+1;j<=i+len-1;j++){
					if(d[i][j]+d[j][i+len]==mi&&x[i+len]-x[j]<=d1){
						sum+=k[i][j]*k[j][i+len];
					}
				}
				if(sum==2){
					ans++;
				}
				k[i][i+len]=min(sum,3);
			}
		}
		//for(int i=1;i<=n;i++){
			//for(int j=i+1;j<=n;j++){
				//cout<<i<<' '<<j<<':'<<k[i][j]<<'\n';
			//}
		//}
		cout<<ans<<'\n';
	}
}