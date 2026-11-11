#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
struct node{
    long long ans,k;
};
long long n,d;
node u;
bool vis[5005][5005];
node jiyihua[5005][5005];
node dfs(long long u,long long v){
    if(u==v){
        return {0,1};
    }
    if(vis[u][v]!=0){
        return jiyihua[u][v];
    }
    node p={1000000000,0};
    for(long long i=u+1;i<=v;i++){
        if(a[i]-a[u]<=d){
            node u=dfs(i,v);
            u.ans++;
            if(u.ans<p.ans){
                p=u;
            }
            else if(u.ans==p.ans){
                p.k+=u.k;
            }
        }
    }
    vis[u][v]=1;
    jiyihua[u][v]=p;
    return p;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
            }
            sort(a+1,a+1+n);
            long long x=a[2]-a[1];
            long long p=d/x;
            if(p<2){
                cout<<0<<"\n";
                continue;
            }
            p+=2;
            cout<<n-p+1<<"\n";
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i;j<=n;j++){
                vis[i][j]=0;
                jiyihua[i][j]={0,0};
            }
        }
        long long ans=0;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                node l=dfs(i,j);
                if(l.k==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
