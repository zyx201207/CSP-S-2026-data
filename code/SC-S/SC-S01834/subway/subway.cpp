#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
struct pir{
	int frst;
	int scond;
};
int sta[500010];
int a[510][50010],t[510][50010],k[510],nt[510][50010],inq[50010];
long long ti[500010];
vector<pir> g[500010];
int c,n,m,d,Q,ans=0;
queue<pir> q;
void bfs(int x,int y){
	ti[x]=0;
	pir aa;
	aa.frst=x;
	aa.scond=0;
	q.push(aa);
	inq[x]=1;
	while(!q.empty()){
		pir p=q.front();
		q.pop();
		inq[p.scond]=0;
		for(int i=0;i<=g[p.scond].size()-1;i++){
			int f=g[p.scond][i].frst;
			int s=g[p.scond][i].scond;
			if(inq[s]==1){
				continue;
			}
			if(p.frst==0){
				aa.frst=f;
				aa.scond=s;
				long long tt=ti[p.scond]+t[f][nt[f][s]];
				if(ti[s]<=tt){
					continue;
				}
				ti[s]=tt;
				q.push(aa);
				inq[s]=1;
				continue;
			}
			if(f!=p.frst){
				long long tt=ti[p.scond]+t[f][nt[f][s]]+t[p.frst][nt[p.frst][p.scond]];
				if(ti[s]>tt){
					aa.frst=f;
					aa.scond=s;
					q.push(aa);
					inq[s]=1;
					ti[s]=tt;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>sta[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			nt[i][a[i][j]]=j;
			if(j==1){
				continue;
			}
			pir bb;
			bb.frst=i;
			bb.scond=a[i][j-1];
			g[a[i][j]].push_back(bb);
			bb.scond=a[i][j];
			g[a[i][j-1]].push_back(bb);
		}
	}
	for(int i=1;i<=Q;i++){
		for(int j=1;j<=n;j++){
			ti[j]=1e18;
		}
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		ans+=sta[x];
		ans+=sta[y];
		cout<<ans+ti[y]<<"\n";
	}
	return 0;
} 
/*
5 5
1 2 4 8 9
      l
    r
      m
5 8
-3 -1 2 2 7
-1 -3 2 2 7
            l
          r
            m   
			5 10
5 10
-10 -1 -3 -3 -2  
-1	-2	-3	-3	-10	-18
			l
					r
       			m   
				   
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/