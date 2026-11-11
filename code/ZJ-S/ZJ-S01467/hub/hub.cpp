#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fir first
#define se second
const int N=1e6+100,K=5010;
const int inf=0x3f3f3f3f;
int read(){
	int x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
int head[N],cnt;
struct edge{
	int u,v;
	int nxt;
}e[N*2];
void add(int u,int v){
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}
bool vis[N];
int f[N];
int find(int x){
	if(x==f[x])return x;
	else return f[x]=find(f[x]);
}
int dis[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id,T;
	id=read(),T=read();
	while(T--){
		ll a,k;
		a=read(),k=read();
		for(int i=1;i<=a;i++){
			head[i]=-1;
		}
		cnt=0;
		for(int i=1;i<a;i++){
			int u,v;
			u=read(),v=read();
			add(u,v),add(v,u);
		}
		if(k==a){
			cout<<0<<"\n";
			continue;
		}else if(k==a-1){
			cout<<1<<"\n";
			continue;
		}
		if(a<=10){
			int tt=inf;
			for(int S=(1<<k)-1;S<(1<<a);S++){
				map<int,int>mp;
				vector<int>v;
				int num=0;
				for(int i=0;i<a;i++){
					if((S>>i)&1)vis[i+1]=1,num++,v.push_back(i+1);
				}
				if(num!=k){
					for(int i=0;i<a;i++){
						if((S>>i)&1)vis[i+1]=0;
					}
					continue;
				}
				for(int i=1;i<=a;i++)f[i]=i;
				for(int i=0;i<v.size();i++){
					int x=v[i];
					for(int j=head[x];~j;j=e[j].nxt){
						int u=e[j].v;
						if(vis[u])f[find(u)]=find(x);
					}
				}
				for(int i=0;i<v.size();i++){
					mp[find(v[i])]++;
				}
				if(mp.size()>2)continue;
				for(int i=1;i<=a;i++){
					dis[i]=inf;
				}
				int ans=0;
				for(int i=1;i<=a;i++){
					if(vis[i]){
						dis[i]=0;
						queue<pair<int,int>>q;
						q.push({i,-1});
						while(!q.empty()){
							pair<int,int>t=q.front();
							q.pop();
							for(int j=head[t.fir];~j;j=e[j].nxt){
								int u=e[j].v;
								if(vis[u]||u==t.se)continue;
								dis[u]=min(dis[u],dis[t.fir]+1);
								q.push({u,t.fir});
							}
						}
					}
				}
				for(int i=1;i<=a;i++)ans=max(ans,dis[i]);
				for(int i=0;i<a;i++){
					if((S>>i)&1)vis[i+1]=0;
				}
				tt=min(tt,ans);
			}
			cout<<tt<<"\n";
			continue;
		}
		cout<<(a*3/5)/k<<"\n";
	}
	
	return 0;
}