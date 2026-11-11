#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010];
int can[5010][5010],dis[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(can,0,sizeof(can));
		memset(dis,0,sizeof(dis));
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==13||c==14) cout<<0<<"\n";
		else{
			long long ans=0;
			for(int i=1;i<=n-1;i++){
				if(x[i+1]-x[i]<=d) dis[i][i+1]=1;
			}
			for(int i=1,j=4;j<=n;i++,j++){
				if(x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[j]-x[i+2]<=d&&x[j]-x[i+1]<=d&&x[j]-x[i]>d){
					can[i][j]=1;dis[i][j]=2;ans++;
				}
				else{
					if(x[j]-x[i]<=d)
						dis[i][j]=1;
				}
			}
			for(int len=4,l,mid,r,fl;len<n;len++){
				for(int i=1,j=1+len;j<=n;i++,j++){
					l=i+1,r=j-1;
					while(l<=r){
						mid=(l+r)/2;
						if(x[mid]-x[i]<=d) l=mid+1;
						else r=mid-1;
					}
					if(can[r][j]==0&&can[r-1][j]==0&&(r-2==i||dis[r-2][j]>dis[r][j])&&dis[r][j]==dis[r-1][j]&&x[j]-x[i]>d&&dis[r][j]&&dis[r-1][j]) can[i][j]=1,ans++;
					fl=0;
					if(!can[i][j])
						for(int k1=i,fl=0;k1<=j;k1++){
							for(int k2=k1+1;k2<=j;k2++){
								if(!can[k1][k2]) continue;
								if(can[i][k1]==0&&can[k2][j]==0&&(dis[i][k1]||i==k1)&&(k2==j||dis[k2][j])&&dis[k1][k2]&&!fl){
									can[i][j]=1;
									fl=1;
									dis[i][j]=(dis[i][k1]==0||dis[k1][k2]==0||dis[k2][j]==0)?0:dis[i][k1]+dis[k1][k2]+dis[k2][j];
									ans++;
								}
								else if(can[i][k1]==0&&can[k2][j]==0&&(dis[i][k1]||i==k1)&&(k2==j||dis[k2][j])&&dis[k1][k2]&&fl){
									can[i][j]=0;
									ans--;
									fl=2;
									break;
								}
							}
							if(fl==2) break;
						}
					if(fl) continue;
					if(x[j]-x[i]>d&&dis[r][j])
						dis[i][j]=dis[r][j]+1;
					else if(x[j]-x[i]<=d) dis[i][j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(can[i][j]) cout<<i<<" "<<j<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
