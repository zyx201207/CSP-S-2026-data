#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
long long c,n,m,d,q,dis[N][N],k,a,t,w[M],u,v;
vector<pair<long long,long long> >st[M];
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans*f;
}
void write(long long ans){
	if(ans<0)putchar('-'),ans=-ans;
	if(ans<10)putchar(ans+'0');
	else write(ans/10),putchar(ans%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		k=read();
		for(int j=1;j<=k;++j){
			a=read(),t=read();
			for(auto v:st[a]){
				dis[v.first][i]=min(dis[v.first][i],v.second+t);
				dis[i][v.first]=min(dis[i][v.first],v.second+t);
			}st[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		u=read(),v=read();
		if(u==v){
			puts("0");
			continue;
		}long long ans=LLONG_MAX;
		for(auto b:st[u]){
			for(auto e:st[v]){
				ans=min(ans,w[u]+w[v]+dis[b.first][e.first]+b.second+e.second);
			}
		}write(ans);
		puts("");
	}
	return 0;
} 
