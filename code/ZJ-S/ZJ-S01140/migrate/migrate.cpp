#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[5005],cnt[5005][5005],a[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%d",&x[i]);
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[j]-x[i])<d){
						a[i][j]=1;
					}else{
						a[i][j]=2000000005;
					}
					cnt[i][j]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=k+1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(a[k][i]+a[i][j]<a[k][j]){
							a[k][j]=a[k][i]+a[i][j];
							cnt[k][j]=1;
						}else if(a[k][i]+a[i][j]==a[k][j]){
							cnt[k][j]++;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%d",&x[i]);
			}
			int s=x[2]-x[1];
			if(d<2*s) cout<<'0'<<endl;
			else{
				int v=d/s;
				cout<<n-2*v+1<<endl;
			}
		}
	}
	return 0;
}