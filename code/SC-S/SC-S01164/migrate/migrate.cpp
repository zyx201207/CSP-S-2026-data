#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static inline ll read(){
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}

static inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=2e6+5;
const int INF=0x3f;
int c,t,ans=0;
int n;ll d;
ll a[N];
vector<int> l[N];

static inline void add(int u,int v){
	l[u].push_back(v);
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;++i) a[i]=read(),l[i].clear();
		queue<int> qq;
		for(int i=1;i<=n;++i){
			while(!qq.empty()&&a[qq.front()]+d<a[i]) qq.pop();
			for(int j=1;j<=qq.size();++j) add(qq.front(),i),qq.push(qq.front()),qq.pop();
			qq.push(i);
		}
		
//		for(int i=1;i<=n;++i){
//			cout<<i<<"  :  ";
//			for(const int v:l[i]){
//				cout<<v<<' ';
//			}cout<<'\n';
//		}
		
		ans=0;
		for(int i=1;i<=n;++i){
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
			q.push({0,i});
			int dis[n+5],cnt[n+5];
			memset(dis,INF,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			while(!q.empty()){
				pair<int,int> ft=q.top();q.pop();
				int u=ft.second;
				if(dis[u]==ft.first) cnt[u]++;
				dis[u]=ft.first;
				for(const int &v:l[u]){
					if(dis[v]>dis[u]+1) q.push({dis[u]+1,v});
//					if(dis[v]==dis[u]+1) cnt[v]++;
				}
			}
			for(int j=i+1;j<=n;++j) if(cnt[j]==1) ans++;
		}
		
		write(ans);putchar('\n');
	}
	
	return 0;
}