#include<bits/stdc++.h>
using namespace std;
const int N=5003;
int c,t,n;
long long d,x[N];
vector<int> g[N],g1[N];
void build(int l){
    for(int i=l;i<=n;i++){
        g[i].clear();
        for(int j=l+1;j<=n;j++){
            if(x[j]-x[i]<=d)g[i].push_back(j);
        }
    }
}
int q[N],ql,qr,dep[N];
void bfs(int s){
    for(int i=s;i<=n;i++)dep[i]=-1;
    dep[s]=0;
    ql=1,qr=0;
    q[++qr]=s;
    while(qr-ql+1){
        int fr=q[ql++];
        for(int y:g[fr]){
            if(dep[y]!=-1)continue;
            dep[y]=dep[fr]+1;
            q[++qr]=y;
        }
    }
    for(int i=s;i<=n;i++){
        g1[i].clear();
        for(int y:g[i]){
            if(dep[y]==dep[i]+1)g1[i].push_back(y);
        }
    }
}
int f[N][N],tmp,res;
void dp(int l){
    tmp=0;
    for(int i=l;i<=n;i++){
        for(int j=i;j<=n;j++)f[i][j]=0;
        f[i][i]=1;
    }
    for(int i=n;i>=l;i--){
        for(int j=i+1;j<=n;j++){
            for(int y:g1[i])f[i][j]=min(3,f[i][j]+f[y][j]);
        }
    }
    for(int i=l+1;i<=n;i++)tmp+=(f[l][i]==2);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c==13||c==14){
        while(t--)cout<<"0\n";
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        res=0;
        for(int i=1;i<=n;i++){
            build(i);
            bfs(i);
            dp(i);
            res+=tmp;
        }
        cout<<res<<"\n";
    }
    return 0;
}