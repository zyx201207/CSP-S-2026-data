#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
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
int c,t,n;
ll d,x[N],dis[N],cnt[N];
bool vis[N];
vector<int> g[N];
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		for(int i=1;i<=n;i++) g[i].clear();
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				g[i].push_back(j);
				//cout<<i<<' '<<j<<'\n';
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)  dis[j]=1e18,cnt[j]=0,vis[j]=0;
			queue<int> q;
			q.push(i);
			dis[i]=0;cnt[i]=1;
			vis[i]=1;
			while(!q.empty()){
				int now=q.front();
				q.pop();
				for(auto to:g[now]){
					if(dis[to]>dis[now]+1){
						dis[to]=dis[now]+1;
						//if(to==10 && dis[to]==3) cout<<now<<' '<<cnt[now]<<'\n';
						cnt[to]=cnt[now];
						if(!vis[to] && cnt[to]<=2) q.push(to);
						vis[to]=1;
					}else if(dis[to]==dis[now]+1){
						cnt[to]+=cnt[now];
						//if(to==10 && dis[to]==3) cout<<now<<' '<<cnt[now]<<'\n';
						if(!vis[to] && cnt[to]<=2) q.push(to);
						vis[to]=1;
					}
				}
			}
			/**if(i==5){
				cout<<"cnt:"<<cnt[10]<<' '<<dis[10]<<'\n';
			}*/
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
					//cout<<i<<' '<<j<<'\n';
				} 
			} 
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
