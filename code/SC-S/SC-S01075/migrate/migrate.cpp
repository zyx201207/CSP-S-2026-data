#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,x[2000005],cnt[2000005],f[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		for(int k=1;k<=n;k++){
			for(int i=k;i<=n;i++) f[i]=1e18,cnt[i]=0;
			f[k]=0;
			cnt[k]=1;	
			for(int i=k;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]>d) break;
					if(f[j]>f[i]+1){
						f[j]=f[i]+1;
						cnt[j]=cnt[i]; 
					}
					else if(f[j]==f[i]+1) cnt[j]++;
				}
			}
			for(int i=k;i<=n;i++) if(cnt[i]==2) ans++;	
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
