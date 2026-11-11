#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
#define pri priority_queue
using namespace std;
const int MX=9223372036854775807;
int firs[1000005],nex[1000005],w[1000005],to[1000005],tot=0,dis[1000005],b[1000005],a[1000005],ord=0;
void add(int x,int y,int z,int cnt){
	nex[++tot]=firs[x];
	firs[x]=tot;
	to[tot]=y;
	w[tot]=z;
	dis[tot]=cnt;
}
int bfs(int s,int t,int cnt){
	if(s==t){
		return w[t];
	}
	queue<int>q;
	queue<int>qq;
	if(b[s]){
		return -1;
	}
	b[s]=1;
	int num=0;
	for(int i=firs[s];i;i=nex[i]){
		q.push(i);
		qq.push(dis[i]);
		if(dis[i]!=cnt){
			num+=w[i]+w[s];
		}
	}
	int minn=MX;
	int flag=0;
	while(!q.empty()){
		int e=q.front(),ee=qq.front();
		int res=bfs(to[e],t,ee);
		if(res!=-1){
			minn=min(res,minn);
			flag=1;
		}else if(!flag){
			return -1;
		}
		q.pop();
		qq.pop();
	}
	if(flag){
		return minn+num;
	}
}
void solve(){
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		a[i]=t;
	}
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		++ord;
		int s,t;
		cin>>s>>t;
		for(int j=2;j<=cnt;j++){
			int ss,tt;
			cin>>ss>>tt;
			add(s,ss,t,ord);
			add(ss,s,tt,ord);
			s=ss,t=tt;
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		cout<<a[s]+a[t]+bfs(s,t,dis[firs[s]])+w[s]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		int c;
		cin>>c;
		solve();
	}
	return 0;
}
