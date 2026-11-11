#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node1{
    int node,wor,line;
};
int ans=1e9;
node1 v[1011][1011];
int siz[10111];
int w[501111];
void dfs(node1 n1,int ans1,int en){
    if(n1.node==en){
        ans=min(ans,ans1);
        return;
    }
    for(int i=1;i<=siz[n1.node];i++){
        if(v[n1.node][i].line!=n1.line){
            ans1=ans1+n1.wor+v[n1.node][i].wor;
            dfs(v[n1.node][i],ans1,en);
        }
        else dfs(v[n1.node][i],ans1,en);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int x[10111];
        int t[10111];
        for(int i=1;i<=k;i++){
            cin>>x[i];
            cin>>t[i];
        }
        for(int i=1;i<k;i++){
            node1 t1;
            t1.node=x[i+1];
            t1.wor=t[i+1];
            t1.line=n;
            v[x[i]][i]=t1;
            siz[x[i]]++;
            node1 t2;
            t2.node=x[i];
            t2.wor=t[i];
            t2.line=n;
            v[x[i+1]][i]=t2;
            siz[x[i+1]]++;
        }

    }
    for(int i=1;i<=q;i++){
        int ans=0,b,e;
        cin>>b>>e;
        node1 ttt;
        ttt.node=b;
        ttt.t=w[b];
        ttt.line=-1;
        dfs()
        ans=ans+w[b]+w[e];
        cout<<ans<<endl;
        ans=1e9;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
