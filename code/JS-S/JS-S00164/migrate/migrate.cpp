#include<bits/stdc++.h>
using namespace std;
//mutiple:clear!!!
const long long inf=1e9;
int c,t;
int n;
long long d;
long long x[2000005];
int dis[2000005];
long long minn(long long a,long long b){
    return (a<b?a:b);
}
void dfs(int u,int v){
    //cout<<u<<' '<<v;
    if(u>=v)return;
    //cout<<"ok"<<endl;
    int pos=u+1;
    while(x[pos]-x[u]<=d&&pos<=v){
        dis[pos]=minn(dis[pos],dis[u]+1);
        //cout<<pos<<endl;
        dfs(pos,v);
        pos++;
    }
}
long long cnt=0;
void dfsc(int u,int v,long long dist){
    if(cnt>2||dist>dis[v])return;
    if(u>=v){
        cnt++;
        return;
    }
    int pos=u+1;
    while(x[pos]-x[u]<=d){
        dfsc(pos,v,dist+1);
        pos++;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int ans=0;
        for(int l=1;l<=n;l++){
            for(int r=l+3;r<=n;r++){
                for(int i=l;i<=r;i++){dis[i]=inf;}
                cnt=0;
                dis[l]=0;
                if(x[r]-x[l]<=d)continue;
                dfs(l,r);
                dfsc(l,r,0LL);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

