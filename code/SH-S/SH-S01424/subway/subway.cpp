#include<bits/stdc++.h>
using namespace std;
const int N=555,M=5e5+5;
const long long INF=1e18;
typedef long long ll;
ll dis[N][N];
ll edge[N][N];
int cnt[M];
vector<int> trans;
vector<int> G[M];
int vis[M][N];
bool f[M];
int in(){
	bool flag=0;
	int num=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			flag=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	if(flag)
		num=-num;
	return num;
}
void out(ll num){
	if(num<0){
		putchar('-');
		num=-num;
	}
	if(num>9)
		out(num/10);
	putchar('0'+num%10);	
}
int c,n,m,d,q,w[M],st,tim,k,a,b;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				edge[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
		edge[i][i]=0;
	int len=trans.size(),idx,len2;
	for(int i=0;i<len;i++){
		idx=trans[i];
		len2=G[idx].size();
		for(int j=0;j<len2-1;j++){
			for(int h=j+1;h<len2;h++){
				if(vis[idx][G[idx][j]]>0&&vis[idx][G[idx][h]]>0){
					if(edge[G[idx][j]][G[idx][h]]>vis[idx][G[idx][h]]+vis[idx][G[idx][j]]){
						edge[G[idx][j]][G[idx][h]]=vis[idx][G[idx][h]]+vis[idx][G[idx][j]];
						edge[G[idx][h]][G[idx][j]]=vis[idx][G[idx][h]]+vis[idx][G[idx][j]];
					}
				}
			}
		}
	}
}
void floyed(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				continue;
			for(int k=1;k<=n;k++){
				if(dis[i][k]+edge[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+edge[k][j];
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)
		if(dis[i][j]>dis[j][i])
			dis[i][j]=dis[j][i];
		else
			dis[j][i]=dis[i][j];
	}
}
ll solve(){
	ll ans=INF;
	int len1=G[a].size(),len2=G[b].size();
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++)
			if(ans>(ll)w[a]+w[b]+vis[a][G[a][i]]+vis[b][G[b][j]]+dis[G[a][i]][G[b][j]])
				ans=(ll)w[a]+w[b]+vis[a][G[a][i]]+vis[b][G[b][j]]+dis[G[a][i]][G[b][j]];
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in(),d=in(),q=in();
	for(int i=1;i<=m;i++)
		w[i]=in();
	for(int i=1;i<=n;i++){
		k=in();
		for(int j=1;j<=k;j++){
			st=in(),tim=in();
			cnt[st]++;
			if(!f[st]&&cnt[st]>1){
				trans.push_back(st);
				f[st]=1;
			}
			vis[st][i]=tim;
			G[st].push_back(i);
		}
	}
	init();
	floyed();
	for(int i=1;i<=q;i++){
		a=in(),b=in();
		out(solve());
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
}
