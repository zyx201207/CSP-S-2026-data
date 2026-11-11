//1~11,12~15,20~21:17*4=68
#include<bits/stdc++.h>
using namespace std;
//1~11
const int N=502,M=1002,P=N+M;
int w[N];
long long f[P][P];
//12~15
struct e{int v,w;};
vector<e>g[P];
struct s{
    int i;long long d;
    bool operator<(s y)/*MUST*/const/*MUST*/{return this->d>y.d;}
};
bool b[P];long long d[P];
//20~21
long long toa[M],tob[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n/*line*/,m/*point*/,temp,q;cin>>c>>n>>m>>temp>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    int k,a,t,a2,t2,x,y;
if(c<=11){//Floyd p^3+q=1e9(?)
    memset(f,63,sizeof(f));
    while(n--){
        cin>>k;
        if(k==1){
            cin>>a>>t;
            continue;
        }else if(k==2){
            cin>>a>>t>>a2>>t2;
            f[a][a2]=f[a2][a]=t+t2;
        }else{
            m++;
            while(k--){
                cin>>a>>t;
                f[a][m]=f[m][a]=t;
            }
        }
    }
    for(int k=1;k<=m;k++)for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        cin>>x>>y;
        cout<<w[x]+f[x][y]+w[y]<<'\n';
    }
}else if(c<=15){//Dijikstra qplogp=2e3*2.05e4*16-=6.4e8(?)
    while(n--){
        cin>>k;
        if(k==1){
            cin>>a>>t;
            continue;
        }else if(k==2){
            cin>>a>>t>>a2>>t2;
            g[a].push_back({a2,t+t2});
            g[a2].push_back({a,t+t2});
        }else while(k--){
            cin>>a>>t;
            g[++m].push_back({a,t});
            g[a].push_back({m,t});
        }
    }
    while(q--){
        cin>>x>>y;
        priority_queue<s>q;
        memset(b,false,sizeof(b));
        memset(d,63,sizeof(d));
        b[x]=1;d[x]=w[x];
        q.push({x,d[x]});
        for(int i=1;i<m;i++){
            int t=q.top().i;q.pop();
            if(t==y){
                cout<<d[y]<<'\n';
                break;
            }
            for(int j=0;j<g[t].size();j++){
                if(d[t]+g[t][j].w<d[g[t][j].v]){
                    d[g[t][j].v]=d[t]+g[t][j].w;
                    q.push({g[t][j].v,d[g[t][j].v]});
                }
            }
        }
    }
}else if(c>=20&&c<=21){
    memset(toa,63,sizeof(toa));
    memset(tob,63,sizeof(tob));
    cin>>k;
    while(k--){
        cin>>a>>t;
        toa[a]=t;
    }
    cin>>k;
    while(k--){
        cin>>a>>t;
        tob[a]=t;
    }
    long long sw=1e18;
    for(int i=1;i<=m;i++)sw=min(toa[i]+tob[i],sw);
    while(q--){
        cin>>x>>y;
        cout<<w[x]+min(min(toa[x]+toa[y],toa[x]+sw+tob[y]),min(tob[x]+sw+toa[y],tob[x]+tob[y]))+w[y]<<'\n';
    }
}
    return 0;
}
