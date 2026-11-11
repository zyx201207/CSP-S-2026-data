#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MaxN=2e6+5,MaxB=5e3+5;

typedef pair<int,int> node;

int C,T;
int n,D;
int X[MaxN];
vector <int> G[MaxN];
int dis[MaxB];
int sem[MaxB];
int trm[MaxB];

bool vis[MaxB];

int read(){
	int f=0,x=1;
	char c=getchar();
	while((c<'0' or c>'9') and c!='-'){
		c=getchar();
	}
	if(c=='-') x=-1,c=getchar();
	while(c>='0' and c<='9'){
		f=f*10+c-'0';
		c=getchar();
	}
	return f*x;
}
void print(int x){
	if(x<0) putchar('-');
	x=abs(x);
	if(x>9) print(x/10);
	putchar((char)(x%10+'0'));
	return ;
}

void Dijkstra(int st){
	priority_queue <node,vector <node> ,greater <node> > q;
	q.push({0,st});
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	memset(sem,0x3f,sizeof sem);
	memset(trm,0x3f,sizeof trm);
	dis[st]=0;
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:G[u]){
			if(vis[v]==0){
				if(dis[u]+1<dis[v]){
					if(sem[u]+1<sem[v]){
						trm[v]=min(sem[v],trm[u]+1);
						sem[v]=sem[u]+1;
					}
					else{
						trm[v]=min(trm[v],sem[u]+1);
					}
					dis[v]=dis[u]+1;
				}
				else if(dis[u]+1<sem[v]){
					trm[v]=min(sem[v],sem[u]+1);
					sem[v]=dis[u]+1;
				}
				else if(dis[u]+1<trm[v]){
					trm[v]=dis[u]+1;
				}
				q.push({dis[v],v});
			}
		}
	}
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();
	T=read();
	for(;T;T--){
		n=read();
		D=read();
		int ans=0,Cent=0;
		bool Tepan1=1,Tepan2=0;
		int Diff=0;
		for(int i=1;i<=n;i++) X[i]=read();
		Diff=X[2]-X[1];
		for(int i=2;i<=n;i++){
			if(X[i]-X[i-1]!=Diff){
				Tepan1=0;
			}
			if(X[i]-X[1]<=D and X[n]-X[i]<=D){
				Tepan2=1;
				Cent=i;
			}
		}
		if(n<=5000){
			for(int i=0;i<=n;i++) G[i].clear();
			memset(dis,0x3f,sizeof dis);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(X[i]-X[j])<=D){
						G[i].push_back(j);
						G[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++){
				Dijkstra(i);
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					if(dis[j]==sem[j] and sem[j]!=trm[j]){
						ans++;
					}
				}
			}
			print(ans/2);
			cout<<endl;
		}
		else if(Tepan1){
			if(D<=Diff){
				cout<<0<<endl;
				continue;
			}
			print(max(0ll,n-2*(D/Diff)+1));
			cout<<endl;
			continue;
		}
		else if(Tepan2){
			for(int i=1;i<Cent;i++){
				int L=upper_bound(X+1,X+n+1,D+X[i])-X;
				int pos=upper_bound(X+1,X+n+1,D+X[i])-X-1;
				if(pos==Cent) pos--;
				int R=upper_bound(X+1,X+n+1,D+X[pos])-X-1;
				ans+=R-L+1;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
