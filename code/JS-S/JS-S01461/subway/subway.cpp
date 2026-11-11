#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500011];
int k[510];
vector<pair<int,int>> ds[500011];
vector<int> cot[510];
bool inl[50011][501];
bool sv[50011][501];
long long dis[500001];
struct node{
    int p;
    long long cs;
    int wy;
};
long long dfs(int s,int t,int wy){
//    cerr<<s<<' '<<t<<' '<<wy<<'\n';
    if(s==t){
        for(int i=0;i<ds[t].size();++i){
            if(ds[t][i].first==wy) return ds[t][i].second;
        }
    }
    if(sv[s][wy]&&wy!=0) return 10000000000000000;
    sv[s][wy]=1;
    long long as=10000000000000000;
    for(int i=1;i<=m;++i){
        if(i==s) continue;
        if(inl[i][wy]) as=min(as,dfs(i,t,wy));
    }
    int tm=0;
    for(int i=0;i<ds[s].size();++i){
        if(ds[s][i].first==wy){
            tm=ds[s][i].second;
            break;
        }
    }
//    cerr<<tm<<'\n';
    for(int i=0;i<ds[s].size();++i){
        if(wy==ds[s][i].first) continue;
        as=min(as,dfs(s,t,ds[s][i].first)+tm+ds[s][i].second);
    }
    return as;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            int a,t;
            cin>>a>>t;
            cot[i].push_back(a);
            inl[a][i]=1;
            ds[a].push_back({i,t});
        }
    }
    if(c>=12&&c<=19){
        int T=ds[1][0].second;
        while(q--){
            int x,y;
            cin>>x>>y;
            for(int i=1;i<=m;++i) dis[i]=10000000000000000;
            deque<node> qe;
            qe.push_front({x,0,0});
            while(!qe.empty()){
                node ss=qe.front();
                qe.pop_front();
                if(dis[ss.p]<ss.cs) continue;
                dis[ss.p]=ss.cs;
                for(int i=0;i<cot[ss.wy].size();++i){
                    if(cot[ss.wy][i]==ss.p) continue;
                    qe.push_front({cot[ss.wy][i],ss.cs,ss.wy});
                }
                for(int i=0;i<ds[ss.p].size();++i){
                    int way=ds[ss.p][i].first;
                    for(int j=0;j<cot[way].size();++j){
                        if(cot[way][j]==ss.p) continue;
                        qe.push_back({cot[way][j],ss.cs+2,way});
                    }
                }
            }
            cout<<w[x]+w[y]+T*dis[y]<<'\n';
        }
        return 0;
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j) sv[i][j]=0;
        }
        cout<<w[x]+w[y]+dfs(x,y,0)<<'\n';
    }
    return 0;
}
//SXY bless me