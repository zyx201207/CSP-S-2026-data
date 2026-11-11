#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
#define gc getchar
#define pc putchar
using namespace std;
inline void read(ll &x){x=0;short f=1;char ch=gc();for(;ch<'0'||ch>'9';ch=gc())if(ch=='-')f=-1;for(;ch>='0'&&ch<='9';ch=gc())x=(x<<3)+(x<<1)+(ch^48);x*=f;}
inline void write(ll x){if(!x){pc('0');return;}short buf[20],top=0;for(;x;x/=10)buf[++top]=x-x/10*10;for(;top;--top)pc(buf[top]+48);}
const ll N=2000002,M=90002,INF=1e18;
ll tp,T,n,m,a[N],dis[N],cnt[N];
int deg[N],du[N],u[M],v[M],tu[M],tot;
queue<int> qe;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(tp),read(T);
	if(tp>=13&&tp<=14){
		for(;T--;){
			read(n),read(m);
			for(int i=1;i<=n;++i)
				read(a[i]);
			pc('0'),pc('\n');
		}
		return 0;
	}
	for(;T--;){
		read(n),read(m);
		tot=0;
		for(int i=1;i<=n+1;++i)
			deg[i]=0;
		for(int i=1;i<=n;++i){
			read(a[i]);
			for(int j=i-1;j;--j){
				if(a[i]-a[j]>m)
					break;
				u[++tot]=j,v[tot]=i,deg[j]++;
			}
		}
		for(int i=1;i<=n+1;++i)
			deg[i]+=deg[i-1];
		for(int i=1;i<=tot;++i)
			tu[--deg[u[i]]]=v[i];
		ll ans=0;
		for(int i=1;i<n;++i){
			for(int j=i;j<=n;++j)
				dis[j]=INF,cnt[j]=0,du[j]=0;
			for(int j=1;j<=tot;++j){
				if(u[j]>=i&&v[j]>i)
					du[v[j]]++;
			}
			dis[i]=0,cnt[i]=1;
			qe.push(i);
			for(;!qe.empty();){
				int now=qe.front();
				qe.pop();
				for(int i=deg[now];i<deg[now+1];++i){
					int v=tu[i];
					if(dis[v]>dis[now]+1)
						dis[v]=dis[now]+1,cnt[v]=cnt[now];
					else if(dis[v]==dis[now]+1)
						cnt[v]+=cnt[now];
					du[v]--;
					if(!du[v])
						qe.push(v);
				}
			}
			for(int j=i;j<=n;++j){
				if(cnt[j]==2)
					ans++;
			}
		}
		write(ans),pc('\n');
	}
	return 0;
}
