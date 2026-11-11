#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505,P=1e8+5;
int w[M],a[M],t[M];
struct node{
    int start,finaly,walk;
}bian[P];
int x,y,ans=1e9,cnt1;
int cnt=0;
bool vis[M];
void dfs(int sta){
    if(sta==y){
        ans=min(ans,cnt1);
        return;
    }
    for(int i=1;i<=cnt;i++){
        if(bian[i].start==sta&&vis[bian[i].finaly]==0){
            vis[bian[i].finaly]=1;
            cnt1+=bian[i].walk;
            dfs(bian[i].finaly);
            vis[bian[i].finaly]=0;
            cnt1-=bian[i].walk;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<k;j++){
            for(int l=j+1;l<=k;l++){
                cnt++;
                bian[cnt]={a[j],a[l],t[j]+t[l]};
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        vis[x]=1;ans=1e9;
        dfs(x);
        for(int j=1;j<=m;j++){
            vis[j]=0;
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
