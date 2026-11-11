#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+5,INF=1e9;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while ('0'>ch||ch>'9'){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9'){
		x=(x<<1ll)+(x<<3ll)+ch-'0';
		ch=getchar();
	}return f*x;
}
int c,t,n,d,x[maxn],dis[maxn][maxn],cnt[maxn][maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while (t--){
		n=read(),d=read();
		for (int i=1;i<=n;i++) x[i]=read();
		if (c<=6){
			int res=0;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) dis[i][j]=INF,cnt[i][j]=1;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (llabs(x[i]-x[j])<=d) dis[i][j]=1;
			for (int k=1;k<=n;k++)
				for (int i=1;i<=n;i++)
					for (int j=1;j<=n;j++)
						if (dis[i][j]>dis[i][k]+dis[k][j])
							dis[i][j]=dis[i][k]+dis[k][j],
							cnt[i][j]=cnt[i][k]*cnt[k][j];
						else if (dis[i][j]==dis[i][k]+dis[k][j])
							cnt[i][j]++;
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++) if (cnt[i][j]==2) res++;
			cout<<res<<'\n';
		}else cout<<0<<'\n';
	}
	return 0;
}

