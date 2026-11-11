#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL c,t,n,d,x[2000005];
LL cnt[200005],st,num;
struct node{
	LL v,step;
};
vector<LL>g[2000005];
void bfs(LL s,LL t){
	queue<node>q;
	q.push((node){s,0});
	cnt[s]=0;
	while(q.size()){
		LL u=q.front().v;
		LL step=q.front().step;
		q.pop();
		if(u==t){
			if(st==-1)st=step;
			if(st==step)num++;
			if(st>step)return;
		}
		for(int i=0;i<g[u].size();i++){
			LL v=g[u][i];
			if(step+1<=cnt[v]){
				q.push((node){v,step+1});
				cnt[v]=step+1;
			}
		} 
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		LL ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++)cnt[k]=2e6;
				st=-1,num=0;
				bfs(i,j);
				if(num==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
} 
//bufenfen,biebao0a
//rp++ 
