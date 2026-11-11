#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000001],t,f[301][301],s[301][301],c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(f,0x3f,sizeof(f));
		memset(s,0,sizeof(s));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			long long x=d/(a[1]-a[0]);
			cout<<n-(x+x-1)+1;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					s[i][j]=f[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						if(f[i][j]>f[i][k]+f[k][j]){
							f[i][j]=f[i][k]+f[k][j];
							s[i][j]=s[i][k]*s[k][j];
						}else if(f[i][j]==f[i][k]+f[k][j]){
							s[i][j]+=s[i][k]*s[k][j];
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
