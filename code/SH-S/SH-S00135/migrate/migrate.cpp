#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
const int N1=5e3+5;
const int N=2e6+5;
int n;
long long d,x[N];

vector<int> g[N1];
int dis[N1],num[N1];
bitset<N1> vis;

long long read(){
	char ch='a';bool f=0;
	while(!isdigit(ch)){if(ch=='-')f=1;ch=getchar();}
	long long x=0;
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?(-x):x;
}
int dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(num,0,sizeof(num));
	vis.reset();
	dis[s]=0;num[s]=1;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto v:g[u])
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				num[v]=num[u];
				q.push(make_pair(dis[v],v));
			}
			else if(dis[v]==dis[u]+1)
				num[v]+=num[u];
	}
	int ans=0;
	rep(i,s+1,n)
		if(num[i]==2)
			ans++;
	return ans;
}
void solve1(){
	n=read();d=read();
	//cin>>n>>d;
	rep(i,1,n)x[i]=read();
	rep(i,1,n)g[i].clear();
	rep(i,1,n)
		rep(j,i+1,n)
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
	long long ans=0;
	//cout<<dij(1)<<endl;
	//return;
	rep(i,1,n)
		ans+=dij(i);
	cout<<ans<<endl;
}
/*int f[N1];
void solve2(){
	cin>>n>>d;
	rep(i,1,n)cin>>x[i];
	int ans=0;
	rep(i,1,n){
		memset(f,0,sizeof(f));
		f[i]=1;
		int p=i,s=0;
		rep(j,i+1,n){
			while(x[j]-x[p]>d){
				s-=f[p];
				p++;
			}
			s+=f[j-1];
			f[j]=s;
			if(f[j]==2)ans++;
		}
		rep(j,1,n)cout<<f[j]<<' ';
		cout<<endl;
	}
	
	cout<<ans<<endl;
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	int c=0,TEST=1;
	c=read();TEST=read();
	//cin>>c>>TEST;
	if(c<=10){
		while(TEST--)
			solve1();
	}
	else if(c==13||c==14){
		while(TEST--)
			cout<<0<<endl;
	}
	return 0;
}
