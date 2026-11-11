#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

struct ND{
    int a;//station number passed by line
    int t;//line to hall
};

int c;
int n;//line count
int m;//station count
int d;//max line count of one station
int q;//trip count
int w[N];//outside to hall

int mp[310][310];
ND ln[310];
int ans;
bool vis[310];

void dfs(int tm,int nd,int tmAns){
    if(ans!=-1&&tmAns>=ans){
        return;
    }
    if(tm==nd){
        ans=tmAns;
        return;
    }
    vis[tm]=true;
    for(int i=1;i<=m;i++){
        if(mp[tm][i]!=-1&&(!vis[i])){
            dfs(i,nd,tmAns+mp[tm][i]);
        }
    }
    vis[tm]=false;
}

void cs1(){//m<=300
    memset(mp,-1,sizeof(mp));
    int k;
    int r;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>ln[j].a>>ln[j].t;
            for(int p=1;p<j;p++){
                if(mp[ln[p].a][ln[j].a]!=-1){
                    mp[ln[p].a][ln[j].a]=min(mp[ln[p].a][ln[j].a],ln[p].t+ln[j].t);
                    mp[ln[j].a][ln[p].a]=mp[ln[p].a][ln[j].a];
                }else{
                    mp[ln[p].a][ln[j].a]=ln[p].t+ln[j].t;
                    mp[ln[j].a][ln[p].a]=mp[ln[p].a][ln[j].a];
                }
            }
        }
    }
/*
    {
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cout<<mp[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
*/
    //k is start
    //r is end
    while(q--){
        cin>>k>>r;
        ans=-1;
        memset(vis,0,sizeof(vis));
        dfs(k,r,0);
        ans+=w[k];
        ans+=w[r];
        cout<<ans<<"\n";
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cs1();

    return 0;
}
