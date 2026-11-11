#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=2e6+10;
const int M=2e6+10;
struct node{
	int to;
	int nxt;
}e[M];
ll step[N];
int head[N];
ll dis[N];
int cnt[N];
//bool vis[N];
int len;
void add(int u,int v){
	e[++len].to=v;
	e[len].nxt=head[u];
	head[u]=len;
}
int n;
ll d;
struct quebfs{
	int u,d;
}q[N];
bool cmp(quebfs x,quebfs y){
	return x.d<y.d;
}
void dij(){
	queue<quebfs>q;
	memset(cnt,0,sizeof(cnt));
	memset(dis,0x3f,sizeof(dis));
	cnt[1]=1;
	dis[1]=1;
	q.push({1,0});
	while(!q.empty()){
		int u=q.front().u,dd=q.front().d;
		q.pop();
//		cout<<u<<" "<<dd<<"\n";
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dd+1<dis[v]){
				dis[v]=dd+1;
				cnt[v]=cnt[u];
				q.push({v,dd+1});
			}
			else if(dd+1==dis[v]){
				cnt[v]+=cnt[u];
				q.push({v,dd+1});
			}
		}
	}
}
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		rep(i,1,n){
			cin>>a[i];
		}
		rep(j,2,n){
			for(int i=j-1;i>=1;i--){
				if((a[j]-a[i])>d)break;
				add(i,j);
			}
		}
		dij();
		ll ans=0;
		rep(i,2,n){
//			cout<<cnt[i]<<" ";
			if(cnt[i]==2){
				ans++;
			}
		}
//		cout<<"\n";
//		rep(i,1,n){
//			cout<<dis[i]<<" ";
//		}cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}

