#include<bits/stdc++.h>
using namespace std;

int c,t,a[210000],ans,s[210000];
bool b[210000];
struct Info{
	int id,sum;
};
vector<Info> g[210000];
void bfs(int start,int goal){
	queue<int> q;
	q.push(start);
	int num=INT_MAX,summ=0;
	s[start]=0;
	while(q.empty()==false){
		int u=q.front();
		b[u]=true;
		q.pop();
		if(u==goal){
			if(s[u]<num&&s[u]!=-1){
				num=s[u];
				summ=1;
				s[u]=10000000;
			}
			else{
				if(s[u]==num){
					++summ;
					s[u]=10000000;
				}
			}
		}
		for(int i=0;i<g[u].size();i++){
			if(b[g[u][i].id]==false){
				q.push(g[u][i].id);
			}
			if(s[g[u][i].id]>s[u]+g[u][i].sum||s[g[u][i].id]==-1){
				s[g[u][i].id]=s[u]+g[u][i].sum;	
				if(b[g[u][i].id]==true){
					q.push(g[u][i].id);
				}				
			}
		}
	}
	if(num!=INT_MAX&&summ==2){
		++ans;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			g[i].clear();
			b[i]=false;
			s[i]=-1;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d&&i!=j){
					g[i].push_back({j,abs(a[i]-a[j])});
					g[j].push_back({i,abs(a[i]-a[j])});
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||abs(i-j)<=d){
					continue;
				}
				bfs(i,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 