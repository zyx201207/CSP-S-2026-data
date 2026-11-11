#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=305; 
int c,t,f[N][N][N],a[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof f);
		memset(a,0,sizeof a);
		int n,d;cin>>n>>d;
		if(c<=10){
			for(int i=1;i<=n;i++)cin>>a[i],f[i][i][0]=1;
			int ans=0;
			for(int l=2;l<=n;l++){
				for(int j=n;j-l+1>=1;j--){
					int i=j-l+1;
					for(int k=j;k>=i+1;k--){
						if(a[k]-a[i]<=d){
							for(int r=0;r<=j-k;r++){
								if(f[k][j][r]){
									f[i][j][r+1]+=f[k][j][r];
									break;
								}
							}
						}
					}
					for(int r=1;r<=j-i;r++){
						if(f[i][j][r]){
							if(f[i][j][r]==2)ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
		else if(c<=12){
			int ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			int gc=a[2]-a[1];
			gc=d/gc;
			if(gc==0){
				cout<<0<<'\n';
				continue;
			}
			for(int i=3;i<=n;i++){
				if(i+1==2*gc)ans+=n-i;
			}
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++)cin>>a[i];
			int s=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]>d){
					s=i-1;
					break;
				}
			}
			if(!s||s==1||s==n){
				cout<<0<<'\n';
				continue;
			}
			if(a[s+1]-a[s-1]>d){
				cout<<0<<'\n';
				continue;				
			}
			if(s+2<=n&&a[s+2]-a[s-1]<=d||s-2>=1&&a[s+1]-a[s-2]<=d){
				cout<<0<<'\n';
				continue;				
			}
			cout<<n-3<<'\n';
		}
	}
	return 0;
}

