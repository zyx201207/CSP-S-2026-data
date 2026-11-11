#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans,x[2000005],p[2000005],q[2000005],r[2000005],y,l[2000005],zl[5005],dp[5005];
vector<int> v[2000005],w[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		p[1]=1,q[n]=n;
		for(int i=2;i<=n;i++){
			int pp=p[i-1];
			while(x[pp]+d<x[i])pp++;
			p[i]=pp;
		}
		for(int i=n-1;i>=1;i--){
			int pp=q[i+1];
			while(x[pp]>x[i]+d&&pp>0)pp--;
			q[i]=pp;
		}
		/*for(int i=2;i<n-1;i++){
			if(v[i].size()>0&&w[i+1].size()>0)l[++x]=i;
		}
		l[x+1]=n;
		for(int i=1;i<=x;i++){
			
		}*/
			for(int i=1;i<=n;i++){
				zl[i]=1,dp[i]=0;
				int ppp=n;
				for(int j=i+1;j<=n;j++)zl[j]=0;
				int pp=i,o=0;
				while(pp<n){
					if(q[pp]==pp){ppp=pp;break;}
					pp=q[pp];
					dp[pp]=++o;
				}
				for(int j=ppp-1;j>i;j--){
					dp[j]=max(dp[j+1],dp[j]);
				}
				for(int j=i+1;j<=ppp;j++){
					for(int ll=j-1;ll>=i&&ll>=p[j];ll--){
						if(dp[j]==dp[ll]+1){
							zl[j]=min(1000000000000000000,zl[j]+zl[ll]);
						}
					}
				}
				for(int j=i+1;j<=ppp;j++){
					if(zl[j]==2)ans++;
				}
			}
		cout<<ans<<'\n';
	}
}

