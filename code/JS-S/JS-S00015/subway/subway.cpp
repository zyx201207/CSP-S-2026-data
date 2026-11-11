#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,x,y,sum=INT_MAX;
struct st{
    ll v;
    int bo;
};
struct que{
    ll v;
    int bo;
    ll step;
};
queue<que> qu;
vector<st> ve[500005];
ll t[500005],e[500005],f[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c;
        for(int j=1;j<=c;j++){
            cin>>e[j];
            cin>>f[i][e[j]];
            if(j>1){
                for(int ii=1;ii<j;ii++){
                    ve[e[ii]].push_back({e[j],i});
                    ve[e[j]].push_back({e[ii],i});
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        sum=INT_MAX;
        memset(e,-1,sizeof(e));
        qu.push({x,0,0});
        while(!qu.empty()){
            que g=qu.front();
            qu.pop();
            if(g.v==y){
                sum=min(sum,g.step+f[g.bo][g.v]);
                continue;
            }
            if(e[g.v]!=-1&&e[g.v]<=g.step) continue;
            e[g.v]=g.step;
            for(int j=0;j<ve[g.v].size();j++){
                if(g.bo==0||g.bo==ve[g.v][j].bo){
                    qu.push({ve[g.v][j].v,ve[g.v][j].bo,g.step+f[ve[g.v][j].bo][g.v]});
                }
                else{
                    qu.push({ve[g.v][j].v,ve[g.v][j].bo,g.step+f[ve[g.v][j].bo][g.v]+f[g.bo][g.v]});
                    //e[g.v]+=f[ve[g.v][j].bo][g.v];
                }
            }
        }
        cout<<sum+t[x]+t[y]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
