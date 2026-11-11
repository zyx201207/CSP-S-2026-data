#include<bits/stdc++.h>
using namespace std;
const int N = 7e5+10;
struct man{
	int w;
	int to;
    int next;	
} F[N];
struct man2{
	int aa;
	int tt;
} FF[N];
int zhankou[N];
int cnt=0;
int h[N];
int dist[N];
priority_queue<pair<int,int> > q;//距离*-1,编号*-1
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(h,-1,sizeof h);
    int c,n,m,d,T;
    cin>>c>>n>>m>>d>>T;
    bool st[m+100];
    int dist[m+100];
    for(int i=1;i<=m;i++) cin>>zhankou[i];
    for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>FF[j].aa>>FF[j].tt;
		}
		if(k==1) continue; 
		for(int j=1;j+1<=k;j++){
			for(int jj=j+1;jj<=k;jj++){
				F[++cnt].w=FF[j].tt+FF[jj].tt;	
			F[cnt].next=h[FF[j].aa];
			h[FF[j].aa]=cnt;
			F[cnt].to=FF[jj].aa;
			F[++cnt].w=FF[j].tt+FF[jj].tt;	
			F[cnt].next=h[FF[jj].aa];
			h[FF[jj].aa]=cnt;
			F[cnt].to=FF[j].aa;
	    }
	}
	}
	while(T--){
		int a,b;
		cin>>a>>b;
		memset(dist,0x3f3f3f3f,sizeof dist);
		memset(st,0,sizeof st);
		dist[a]=0;
		while(!q.empty()){
			q.pop();
		}
		q.push({0,a*-1});
		while(!q.empty()){
            auto t=q.top();
            q.pop();
            if(t.second*-1==b){
				cout<<(t.first*-1)+zhankou[a]+zhankou[b]<<'\n';
				break;
			}
			if(st[t.second*-1]) continue;
            st[t.second*-1]=1;
            for(int i=h[t.second*-1];i!=-1;i=F[i].next){
				if(F[i].w+dist[t.second*-1]<dist[F[i].to]){
					dist[F[i].to]=F[i].w+dist[t.second*-1];
					q.push({dist[F[i].to]*-1,F[i].to*-1});
				}
			}			
		}
	}
	return 0;
}
