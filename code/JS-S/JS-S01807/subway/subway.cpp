#include <bits/stdc++.h>
#define PI pair<long long,int>
using namespace std;
const int M=5e5+10,N=550;
const long long inf=1e18;
struct node{
    int v,w;
};
vector<node>e[N],a[M];
int c,n,m,d,Q,wt[M];
bool vis[M],h[N];
long long dis[N][N];
priority_queue<PI,vector<PI>,greater<PI> >q;
inline int rd(){
	int x=0,f=1;
	char c=getchar_unlocked();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar_unlocked();
	}
	return x*f;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd(),n=rd(),m=rd(),d=rd(),Q=rd();
    for(int i=1;i<=m;i++)wt[i]=rd();
    for(int i=1;i<=n;i++){
        int k=rd(),v,w;
        while(k--){
			v=rd(),w=rd();
            e[i].push_back({v,w});
            a[v].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)dis[i][j]=inf;
    for(int i=1;i<=n;i++){
        for(int j=0;j<e[i].size();j++){
            int v=e[i][j].v;
            for(int k=0;k<a[v].size();k++){
                int ed=a[v][k].v;
                dis[i][ed]=min(dis[i][ed],1ll*a[v][k].w+e[i][j].w);
            }
        }
    }
    for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
	 		for(int j=1;j<=n;j++)
	 			dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
    while(Q--){
        int x,y;
        long long ans=LLONG_MAX;
        cin>>x>>y;
        for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++)
				ans=min(ans,dis[a[x][i].v][a[y][j].v]+a[x][i].w+a[y][j].w);
		cout<<ans+wt[x]+wt[y]<<"\n";
    }
    return 0;
}
