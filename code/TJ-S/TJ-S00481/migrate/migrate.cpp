#include <bits/stdc++.h>
using namespace std;
namespace code1{
	const int N=305;
	long long dis[N][N],x[N];
	int nex[N];
	int la[N];
	int f[N][N][N];
	int sum[N][N][N];
	void solve(){
		int t;
		cin>>t;
		while(t--){
			memset(sum,0,sizeof sum);
			memset(dis,0x3f,sizeof dis);
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			x[n+1]=0x3f3f3f3f3f3f3f3fll;
			int now=2;
			for(int i=1;i<=n;i++){
				while(x[now]-x[i]<=d) now++;
				now--;
				nex[i]=now;
			}
			now=1;
			for(int i=1;i<=n;i++){
				while(x[i]-x[now]>d) now++;
				la[i]=now;
			}
			for(int i=1;i<=n;i++){
				dis[i][i]=0;
				for(int j=i;j<=n;j++){
					for(int k=i+1;k<=nex[j];k++){
						dis[i][k]=min(dis[i][k],dis[i][j]+1);
					}
				}
			}
			
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++){
				f[i][i][0]=1;
				sum[i][i][0]=1;
				//sum[i][i+1][0]=1; 
			}
			for(int i=1;i<=n;i++){
				for(int k=0;k<=n;k++){
					for(int j=i+1;j<=n;j++){
//						for(int l=max(la[j],i);l<j;l++){
//							f[i][j][k]+=f[i][l][k-1];
//						}
						if(k>0) f[i][j][k]=sum[i][j-1][k-1]-sum[i][max(la[j],i)-1][k-1];
						sum[i][j][k]=sum[i][j-1][k]+f[i][j][k];
						//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<" "<<sum[i][j][k]<<endl;
					}
				}
			}
			
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
//					for(int k=1;k<=n;k++){
//						cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
//					}
					//cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
					if(dis[i][j]<=n&&f[i][j][dis[i][j]]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
namespace code2{
	long long a[2000005];
	void solve(){
		int t;
		cin>>t;
		while(t--){
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			if(d<a[2]-a[1]){
				cout<<0<<endl;
				continue;
			}
			long long ans=0;
			int t=d/(a[2]-a[1]);
			for(int l=2;l<=n-1;l++){
				int s=l%t;
				if(s==t-1&&l-1>d) ans+=n-l;
			}
			cout<<ans<<endl;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c==13||c==14) code2::solve(); 
	else code1::solve();
	return 0;
}
/*
2 4 6 8 10 12 14 16 18 20
22 24 26
28
30
*/
