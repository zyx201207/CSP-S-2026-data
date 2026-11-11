#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const int M=305;
int c,T,n;
ll d,a[N];
int cnt[M];
int low[M];
vector<int>e[M];

void planA(){
    while(T--){
        cin>>n>>d; ll ans=0;
        for(int i=1;i<=n;++i)cin>>a[i];
        ll del=a[2]-a[1];
        ll mov=d/del;
        if(mov>1)
        for(int i=1;i<=n;++i){
            if(i*1ll-mov-mov+1>0)++ans;
        }
        cout<<ans<<'\n';
    }
}

void dfs(int u,int dep){
    for(int v:e[u]){
        dfs(v,dep+1);
        if(dep<low[v])
        low[v]=dep,cnt[v]=1;
        else if(low[v]==dep){
            cnt[v]++;
        }
    }
    return ;
}

void planN3(){
    while(T--){
        cin>>n>>d; ll ans=0;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n-i;++j){
                if(a[i+j]-a[i]>d)break;
                e[i].push_back(i+j);
            }
        }
        for(int i=1;i<=n;++i){
            memset(cnt,0,sizeof(cnt));
            memset(low,0x3f,sizeof(low));
            dfs(i,1);
            for(int j=1;j<=n;++j){
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
}

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin>>c>>T;

    if(c>6)planA();
    else  planN3();

    return 0;
}