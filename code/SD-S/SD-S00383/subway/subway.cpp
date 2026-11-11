#include<bits/stdc++.h>
using namespace std;
int cc,n,m,d,q,k,len[500005],w[500005],sum,i,j,x,y;
long long minn[505][505],ans;
vector<int>t[505],c[500005],bh[500005];
char opt;
inline int read(){
	sum=0;
	opt=getchar();
	while(!isdigit(opt))x=getchar();
	while(isdigit(opt)){
		sum=(sum<<1)+(sum<<3)+(opt^48);
		opt=getchar();
	}
	return sum;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cc=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(i=1;i<=m;++i){
		w[i]=read();
		c[i].push_back(0);
		bh[i].push_back(0);
	}
	for(i=1;i<=n;++i){
		k=read();
		t[i].push_back(0);
		for(j=1;j<=k;++j){
			x=read(),y=read();
			t[i].push_back(y);
			c[x].push_back(i);
			++len[x];
			bh[x].push_back(j);
		}
	}
	memset(minn,0x3f,sizeof(minn));
	for(i=1;i<=n;++i)minn[i][i]=0;
	for(i=1;i<=m;++i)for(j=1;j<len[i];++j)for(k=j+1;k<=len[i];++k)minn[c[i][j]][c[i][k]]=min(minn[c[i][j]][c[i][k]],(long long)t[c[i][j]][bh[i][j]]+t[c[i][k]][bh[i][k]]);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)minn[i][j]=min(minn[i][j],minn[j][i]);
	for(k=1;k<=n;++k)for(i=1;i<n;++i)for(j=i+1;j<=n;++j)minn[i][j]=min(minn[i][j],minn[i][k]+minn[k][j]);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)minn[i][j]=min(minn[i][j],minn[j][i]);
	for(;q;--q){
		x=read(),y=read();
		ans=1e18;
		for(i=1;i<=len[x];++i)for(j=1;j<=len[y];++j)ans=min(ans,(long long)minn[c[x][i]][c[y][j]]+t[c[x][i]][bh[x][i]]+t[c[y][j]][bh[y][j]]+w[x]+w[y]);
		cout<<ans<<'\n';
	}
}
