#include<iostream>
#include<algorithm>
#include<queue>
#define N 2000010
#define INF 1145141919810000
using namespace std;
long long head[N],ver[N],Next[N],tot=-1;
void add(long long x,long long y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
long long n,m,flag[N],dis[N],ans;
queue<long long>q;
void dfs(long long k,long long cnt){
	if(k>m){
		for(int i=1;i<=n;++i){
			dis[i]=INF;
			if(flag[i]==1){
				dis[i]=0;
				q.push(i);
			}
		}
		long long maxx=-1;
		while(!q.empty()){
			long long tk=q.front();
			q.pop();
			maxx=max(maxx,dis[tk]);
			for(int i=head[tk];i!=-1;i=Next[i]){
				if(!flag[ver[i]]&&dis[ver[i]]>dis[tk]+1){
					dis[ver[i]]=dis[tk]+1;
					q.push(ver[i]);
				}
			}
		}
		ans=min(ans,maxx);
		return;
	}
	for(int i=1;i<=n;++i){
		if(!flag[i]){
			long long cntt=0;
			for(int j=head[i];j!=-1;j=Next[j]){
				cntt+=flag[ver[j]];
			}
			if(cnt+1-cntt<=2){
				flag[i]=1;
				dfs(k+1,cnt+1-cntt);
				flag[i]=0;
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin>>t>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			head[i]=-1;
			flag[i]=0;
		}
		tot=-1;
		ans=INF;
		for(int i=1;i<n;++i){
			long long x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
100?+100?+eps+eps

meowmeowmeowmeowmeowmeowmeowmeow
meowmeowmeowmeowmeowmeowmeowmeow
meowmeowmeowmeowmeowmeowmeowmeow
meowmeowmeowmeowmeowmeowmeowmeow
meowmeowmeowmeowmeowmeowmeowmeow
meowmeowmeowmeowmeowmeowmeowmeow


I want to be chosen

my luogu account:god_gold

if you see this,please send a message to me

I'm a Furry
*/
