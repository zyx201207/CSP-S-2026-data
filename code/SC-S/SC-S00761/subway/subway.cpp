#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10,M=5e2+10;
inline ll read(){
	ll w=0,f=1;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		w=(w<<3)+(w<<1)+(ch^48);
		ch=getchar();
	}
	return f*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int c,n,m,d,q,x,y;
ll w[N],g[M][M],t;
vector<int> line[N]; 
unordered_map<int,ll> mp[N],have[M];
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,a;j<=k;j++){
			a=read();t=read();
			have[i][a]=t;
			line[a].push_back(i);
			mp[a][i]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) g[i][j]=1e18;
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(auto now:have[i]){
				if(have[j].count(now.first)){
					g[i][j]=min(g[i][j],now.second+have[j][now.first]);
					g[j][i]=min(g[j][i],now.second+have[j][now.first]);
				}
			}
		}
	}
	/**for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<g[i][j]<<' ';
		cout<<'\n';
	}*/
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	/**for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<g[i][j]<<' ';
		cout<<'\n';
	}*/
    while(q--){
    	x=read();y=read();
    	ll ans=0x3f3f3f3f3f3f3f3f;
    	for(auto l:line[x])
    		for(auto r:line[y])
    			ans=min(ans,g[l][r]+mp[x][l]+mp[y][r]);
		ans+=w[x]+w[y];
		write(ans);
		putchar('\n');
	}
	
	return 0;
}
