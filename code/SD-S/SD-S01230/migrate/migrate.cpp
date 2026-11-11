#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000010];
int f[2000010];
long long dist[5010][5010];
bool vis[5010];
long long cnt[5010];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dist[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			f[i]=n;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					f[i]=j-1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
			queue<int> q;
			q.push(i);
			dist[i][i]=0;
			vis[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v=u+1;v<=f[u];v++){
					if(!vis[v]){
						vis[v]=1;
						q.push(v);
						dist[i][v]=dist[i][u]+1;
					}
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++){
//				cout<<"!"<<i<<" "<<j<<" "<<dist[i][j]<<endl;
//			}
//		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[j]=0;
				vis[j]=0;
			}
			cnt[i]=1;
			vis[i]=1;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				
				q.pop();
				for(int v=u+1;v<=f[u];v++){
					//cout<<"#"<<u<<" "<<v<<endl;
					if(dist[i][v]==dist[i][u]+1){
						cnt[v]+=cnt[u];
						if(!vis[v]){
							vis[v]=1;
							q.push(v);
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				//cout<<i<<" "<<j<<" "<<cnt[j]<<endl;
				if(cnt[j]==2&&j!=i){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
