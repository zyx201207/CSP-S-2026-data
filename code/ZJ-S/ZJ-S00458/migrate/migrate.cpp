#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int mx=2e3+10;
const ll inf=1e18;
int c,t;
ll n,d;
ll a[mx];
ll f[mx][mx];
int cnt[mx][mx];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--){
		for(int i=0;i<mx;i++) for(int j=0;j<mx;j++) f[i][j]=inf;
		memset(cnt,0,sizeof(cnt));
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					f[i][j]=1;
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==k||k==j) continue;
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=1;
					}
					else if(f[i][j]==f[i][k]+f[k][j]) cnt[i][j]++;
				}
			}
		}
//		
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++) cout<<f[i][j]<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<cnt[i][j]<<" ";
				if(cnt[i][j]==2) ans++;
			} 
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
