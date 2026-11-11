#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=5e7+5;
int head[N],pro[M],nex[M],cnt=-1;
int dis[5005][5005],ge[5005][5005];
long long a[N];
void ll(int x,int y){
	pro[++cnt]=y;
	nex[cnt]=head[x];
	head[x]=cnt;
}
priority_queue<pair<int,int> > q;
int n;
bool vis[5005];
void dij(int s){
//	printf("%d\n",s);
	for(int i=1;i<=n;i++){
		dis[s][i]=0x3f3f3f3f;
		ge[s][i]=0;
		vis[i]=0;
	}
	dis[s][s]=0;
	ge[s][s]=1;
	q.push({0,s});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int x=t.second;
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(int i=head[x];i!=-1;i=nex[i]){
			int y=pro[i];
//			printf("%d %d %d %d\n",x,y,dis[s][x],dis[s][y]);
			if(dis[s][x]+1<dis[s][y]){
				dis[s][y]=dis[s][x]+1;
				ge[s][y]=ge[s][x];
				q.push({-dis[s][y],y});
			}
			else if(dis[s][x]+1==dis[s][y]){
				ge[s][y]+=ge[s][x];
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--){
		long long d;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(d==1){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){	
			long long ans=0;
			for(int i=1;i<=n;i++){
				long long l,r;
				if(a[i]+d+1>a[n]){
					l=n+1;
				}
				else{
					l=lower_bound(a+1,a+1+n,a[i]+d+1)-a;
				}
				if(a[i]+2*d-1>a[n]){
					r=n;
				}
				else{
					r=lower_bound(a+1,a+1+n,a[i]+2*d)-a-1;
				}
//				printf("%lld %lld\n",l,r);
				if(l<=r){
//					printf("%lld\n",r-l+1);
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
		else if(c<=10){
			for(int i=1;i<=n;i++){
				head[i]=-1;
			}
			cnt=-1;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
//						printf("%d %d\n",i,j);
						ll(i,j);
						ll(j,i); 
					}
				}
			}
			for(int i=1;i<=n;i++){
				dij(i);
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dis[i][j]!=0x3f3f3f3f&&ge[i][j]==2){
						ans++;
					} 
				}
			}
			printf("%lld\n",ans);
		}
	} 
	return 0;
}

