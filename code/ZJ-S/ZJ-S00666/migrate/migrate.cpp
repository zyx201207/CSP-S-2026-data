#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],ans;

queue<int> q;
bool vis[5005];
int dis[5005],cnt[5005];
void bfs(int s){
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int v=1;v<=n;v++){
//			if(v==2 && u==3) cout<<"\n\n<><>"<<(x[v]-x[u])<<"<><>\n\n\n";
			if(v==u || abs(x[v]-x[u])>d) continue;
			if(dis[u]+1>dis[v]) continue;
			if(dis[u]+1<dis[v]) {
				dis[v]=dis[u]+1;
				cnt[v]=1;
				q.push(v);
			}else{
				cnt[v]++;
				if(cnt[v]==2){
					ans++;
//					cout<<"|"<<s<<" "<<v<<" |\n";
				} 
				if(cnt[v]==3) ans--;
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		scanf("%lld",&n);
		scanf("%lld",&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c==11 || c==12){
			if(d<=(x[2]-x[1])){
				printf("0\n");
				continue;
			}
			int cnt=d/(x[2]-x[1]);
			ans+=(n-2*cnt+1);
			printf("%lld\n",max(ans,0LL));
		}else if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) {
					cnt[j]=vis[j]=0;
					dis[j]=0x3f3f3f3f;
				}
				bfs(i);
//				cout<<"s:"<<i<<"\n";
//				for(int j=1;j<=n;j++) cout<<"i:"<<j<<" dis:"<<dis[j]<<"\n";
			}
			printf("%lld\n",ans/2);
		}
	}
	
	return 0;
}