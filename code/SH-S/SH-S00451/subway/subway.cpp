#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=504,M=500005;
ll c,n,m,d,q,x,y,ans,cnt[M],w[M],k[N],f[N][N];
vector<ll> t[M];
map<pair<ll,ll>,int>a;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&x,&y);
			a[make_pair(x,i)]=t[x].size();
			cnt[x]++;
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) 
			f[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int l=1;l<=m;l++){
		if(cnt[l]<2) continue;
		for(int i=1;i<=n;i++){
			if(!a.count(make_pair(l,i))) continue;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(!a.count(make_pair(l,j))) continue;
				f[i][j]=min(t[l][a[make_pair(l,i)]]+t[l][a[make_pair(l,j)]],f[i][j]);
			}
		}
	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][l]+f[l][j],f[i][j]);
	for(int i=1;i<=q;i++){
		scanf("%lld %lld",&x,&y);
		ans=1e9+7;
		for(int j=1;j<=n;j++){
			if(!a.count(make_pair(x,j))) continue;
			for(int l=1;l<=n;l++){
				if(!a.count(make_pair(y,l))) continue;
				ans=min(ans,t[x][a[make_pair(x,j)]]+t[y][a[make_pair(y,l)]]+f[j][l]);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
