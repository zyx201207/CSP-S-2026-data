#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,q,x,y,ans=1e9,W,k;
int w[100005];
bool v[100005];
struct node{
    int t[100005];
    vector <int> fa;
    bool f=0;
}s[505];
vector <int> way[505];
int ffind(int u,int v1){
    for(int i=1;i<=100005;i++){
        if(s[v1].t[i]>0&&s[u].t[i]>0) return i;
    }
}
void dfs(int sub,int sum,int ss){
    if(sub==y){
        ans=min(ans,sum+s[sub].t[ss]);
        return;
    }
    for(int i=0;i<way[sub].size();i++){
        int k1=way[sub][i];
        if(v[k1]){continue;}
        if(s[sub].f==0){
            v[k1]=1;
            dfs(k1,sum,ss);
            v[k1]=0;
        }
        else{
            if(s[k1].t[ss]>0){
                v[k1]=1;
                dfs(k1,sum,ss);
                v[k1]=0;
            }
            else{
                int g=ffind(k1,sub);
                int sumt=s[sub].t[ss]+s[k1].t[g];
                v[k1]=1;
                dfs(k1,sum+sumt,g);
                v[k1]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        int a2;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            s[a].fa.push_back(i);
            s[a].t[i]=t;
            if(j>2){
                way[a].push_back(a2);
                way[a2].push_back(a);
                a2=a;
            }
            else {a2=a;}
            if(s[a].fa.size()>1){s[a].f=1;}
            else s[a].f=0;
        }
    }

    while(q--){
        cin>>x>>y;
        memset(v,0,sizeof(v));
        W=w[x]+w[y];
        for(int i=0;i<s[x].fa.size();i++){
            dfs(x,s[x].t[i],s[x].fa[i]);
        }
        cout<<ans+W<<"\n";
    }
    return 0;
}
