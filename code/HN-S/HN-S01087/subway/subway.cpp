#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar_unlocked();
	}
	return x*f;
}
int c,n,m,d,q,w[500005],k[500005],a[500005],t[500005],dp[505][505];
pair<int,int> v[500005][25];
int siz[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[j]=read(),t[j]=read();
			v[a[j]][siz[a[j]]++]={i,t[j]};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<siz[i];j++){
			int x=v[i][j].first,w1=v[i][j].second;
			for(int k=0;k<siz[i];k++){
				int y=v[i][k].first,w2=v[i][k].second;
				dp[x][y]=dp[y][x]=min(dp[x][y],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int s,t;
		s=read(),t=read();
		int minn=LONG_LONG_MAX;
		for(int j=0;j<siz[s];j++){
			int x=v[s][j].first,w1=v[s][j].second;
			for(int k=0;k<siz[t];k++){
				int y=v[t][k].first,w2=v[t][k].second;
				minn=min(minn,dp[x][y]+w1+w2);
			}
		}
		cout<<minn+w[s]+w[t]<<"\n";
	}
	return 0;
}
