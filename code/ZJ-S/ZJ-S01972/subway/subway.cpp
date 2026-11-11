#include <bits/stdc++.h>
using namespace std;

#define expr constexpr
#define db if(DEBUG)
#define ndb if(!DEBUG)
#define printf db printf
#define P pair<int,int>
#define F first
#define S second
#define pb push_back
#define ass(x) if(!(x)) cerr<<"ERROR on line "<<__LINE__<<endl,exit(1);
#define _sz(x) int((x).size())
#define _all(x) (x).begin(),(x).end()
typedef long long LL;
typedef __int128 i28;

template<typename T>void ckmin(T&x,const T&y) { if(y<x) x=y; }
template<typename T>void ckmax(T&x,const T&y) { if(x<y) x=y; }
//#############################################################
#define DEBUG 0

expr int N=5e5+5,L=505;
expr LL inf = 0x3f3f3f3f3f3f3f3f;

int sub,n,m,d,q;
LL w[N],dis[L][L];
vector<pair<int,LL> >past[N];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ndb ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>sub>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++) {
        cin>>k;
        for(int j=1,x,y;j<=k;j++)
            cin>>x>>y, past[x].pb({i,y});
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i] = 0;
    for(int i=1;i<=m;i++) {
        ass(_sz(past[i])<=d)
        for(auto[x,y]:past[i])
            for(auto[z,t]:past[i])
                ckmin(dis[x][z],y+t);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                ckmin(dis[j][k],dis[j][i]+dis[i][k]);
    printf(">>> dis:\n");
    db for(int i=1;i<=n;i++) {
        db for(int j=1;j<=n;j++)
            printf("%lld ",dis[i][j]);
        printf("\n");
    }
    for(int i=1,s,t;i<=q;i++) {
        cin>>s>>t;
		printf("#################################################### %d -> %d\n",s,t);
        ass(s>=1 && s<=m && t>=1 && t<=m && s!=t)
        LL ans = inf;
        for(auto[x,y]:past[s]) {
            for(auto[z,w]:past[t]) {
				printf("---------------------------------- (%d,%lld) -> (%d,%lld)\n",x,y,z,w);
                ckmin(ans,dis[x][z]+y+w);
				printf("\t--- ckans dis[%d,%d](%lld) + %lld + %lld\n",x,z,dis[x][z],y,w);
            }
        }
		printf("--- w[%d](%lld)+w[%d](%lld) = %lld\n",s,w[s],t,w[t],w[s]+w[t]);
        cout<<ans+w[s]+w[t]<<'\n';
    }
	return 0;
}
/*

*/