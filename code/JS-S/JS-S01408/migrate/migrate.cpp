#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
long long c,T;
long long n,d,ans=0;
long long a[100050];
long long vec[5050][5050],sz[5050],dis[5050],cnt[5050];
bool vis[5050];
void bfs(long long s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	queue<long long> q;
	q.push(s);
	dis[s]=0;
	vis[s]=true;
	cnt[s]=1;
	while(q.empty()==false){
		long long u=q.front();
		q.pop();
		for(long long i=1; i<=sz[u]; i++){
			long long v=vec[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
			}
			else if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
			}
			if(vis[v]==false){
				vis[v]=true;
				q.push(v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			ans=0;
			memset(a,0,sizeof(a));
			for(long long i=1; i<=n; i++){
				cin>>a[i];
			}
			
		}
		return 0;
	}
	else{
		while(T--){
			cin>>n>>d;
			ans=0;
			memset(a,0,sizeof(a));
			memset(sz,0,sizeof(sz));
			memset(vec,0,sizeof(vec));
			for(long long i=1; i<=n; i++){
				cin>>a[i];
			}
			for(long long i=1; i<=n; i++){
				for(long long j=i+1; j<=n; j++){
					if(a[j]-a[i]<=d){
						sz[i]++;
						vec[i][sz[i]]=j;
					}
				}
			}
			for(long long i=1; i<=n; i++){
				bfs(i);
				for(long long j=i+1; j<=n; j++){
					if(cnt[j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
