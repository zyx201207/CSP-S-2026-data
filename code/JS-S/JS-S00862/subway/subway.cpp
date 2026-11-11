#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int t[N],dis[N][21],typ[N][21],cnt[N];
int c[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;cin>>C>>n>>m>>d>>q;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int id,len;cin>>id>>len;
			dis[id][++cnt[id]]=len;
			typ[id][cnt[id]]=i;
		}
	}
	memset(c,0x3f,sizeof(c));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				c[typ[i][j]][typ[i][k]]=min(c[typ[i][j]][typ[i][k]],dis[i][j]+dis[i][k]);
				c[typ[i][k]][typ[i][j]]=min(c[typ[i][k]][typ[i][j]],dis[i][j]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)c[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int S,T;cin>>S>>T;
		int ans=(int)1<<62;
		for(int j=1;j<=cnt[S];j++){
			for(int k=1;k<=cnt[T];k++){
				ans=min(ans,t[S]+t[T]+c[typ[S][j]][typ[T][k]]+dis[S][j]+dis[T][k]);
			}
		}
		cout<<ans<<'\n';
	}
}
