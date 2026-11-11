#include <bits/stdc++.h>
using namespace std;


int c,n,m,d,q;
int fa[555000],tfa[555000];
long long shu[5550];
int shang[5550],xia[5550];
int letgo[550][550];

struct H{
    int u=0,v=0;
    long long w=0;
}K[550000];

int fd(int x){
    if (fa[x]==x){
        return x;
    }
    return fa[x] = fd(fa[x]);
}
vector <pair<int,long long> > mp[550000];
int sz[5550];
bool He(int x,int y,long long w){
    int fx = fd(x),fy = fd(y);
    if (fx!=fy){
        if (sz[fx]>=sz[fy]){
            fa[fy] = fx;
            sz[fx] += sz[fy];
            tfa[y] = x;
            mp[y].push_back({x,w});
            mp[x].push_back({y,w});cout<<x<<" "<<y<<endl;
        }else{
            fa[fx] = fy;
            sz[fy] += sz[fx];
            tfa[x] = y;
            mp[x].push_back({y,w});
            mp[y].push_back({x,w});

        }
    }
}

bool cmp(H x,H y){
    return x.w<y.w;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway2.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=n;i++){
         cin>>shu[i];
         sz[i] = 1;
         fa[i] = i;
         tfa[i] = i;
    }
    int N = n;
    for (int KKK = 1;KKK<=m;KKK++){
        int x;
        cin>>x;
        for (int i=1;i<=x;i++){
            long long t;
            int a;
            cin>>a>>t;
            K[KKK*x+i+n].u = n+x;
            K[KKK*x+i+n].v = a;
            K[KKK*x+i+n].w = t;
        }
        N += x*2;
    }
    for (int i=n+1;i<=N;i++){
         sz[i] = 1;
         fa[i] = i;
         tfa[i] = i;
    }
    sort(K+1,K+1+N,cmp);
    for (int i=1;i<=N;i++){
        He(K[i].u,K[i].v,K[i].w);
    }
    while (q--){
        int start,over;
        cin>>start>>over;
        int xian = start;
        int xian2 = over;
        int cnt = shu[start]+shu[start];
        int cnt2 = shu[over]+shu[start];
        bool fid = 1;
        while (fid){
            fid = 0;
            for (pair<int,long long> K:mp[xian]){
                if (tfa[xian]==K.first){
                    xian = K.first;
                    cnt += K.second;
                    fid = 1;
                    break;
                }
            }
        }
        fid = 1;
        while (fid){
            fid = 0;
            for (pair<int,long long> K:mp[xian2]){
                if (tfa[xian2]==K.first){
                    xian2 = K.first;
                    cnt2 += K.second;
                    fid = 1;
                    break;
                }
            }
        }
        cout << max(cnt,cnt2) <<"\n";
    }
    return 0;
}
