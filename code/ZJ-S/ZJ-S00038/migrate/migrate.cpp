#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2001000;
int c,T,n,d,f[N][4][4],a[N],nxt[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					f[i][j][k]=0;
		nxt[n]=n;
		for(int i=n-1;i>=1;i--){
			nxt[i]=nxt[i+1];
			while(a[nxt[i]]>a[i]+d)--nxt[i];
		}
		for(int i=n;i>=1;i--){
			if(nxt[i]==i)continue;
			for(int j=0;j<4;j++){
				for(int k=1;k<4;k++){
					if(i==1&&(j!=0||k!=1))continue;
					if(i<=2&&k>1)continue;
					int d1=k+(nxt[i-1]==nxt[i])*j,d2=k+(nxt[i-1]>=nxt[i]-1)*j;
					if(d1>3)d1=3;if(d2>3)d2=3;
					if(nxt[i]==i+1)d2=3;
					f[i][j][k]=f[nxt[i]][d2][d1];
					if(i>2&&nxt[i-2]==nxt[i]){
						if(j==0&&k==1)ans+=f[i][j][k];
						f[i][j][k]=0;
						continue;
					}
					if(j&&j+k==2){
						f[i][j][k]+=nxt[i-1]-nxt[i-2];
					}
					if(k==2){
						if(j)f[i][j][k]+=nxt[i]-nxt[i-1];
						else f[i][j][k]+=nxt[i]-nxt[i-2];
					}
					
				}
			}
			ans+=f[i][0][1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
