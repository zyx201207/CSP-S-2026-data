#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
int l[300009];
queue<int>q;
vector<int>tr[300009];
void bfs(){
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int v:tr[u]){
            if (l[v]>l[u]){
                l[v]=l[u]+1;
                q.push(v);
            }
        }
    }
}
void solveA(){
    while(t--){
        cin>>n>>k;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        int m=n/2;
        if (k==n)cout<<"0\n";
        else if (k>=m)cout<<"1\n";
        else{
            int z=m-k;
            z=ceil(1.0*z/4);
            cout<<z+1<<"\n";
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if (c==13||c==14){solveA();return 0;}
    while(t--){
        cin>>n>>k;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        int res=1e9;
        for (int i=1;i<(1<<n);i++){
            int cnt=0;
            for (int j=1;j<=n;j++){
                if ((i>>j-1)&1)cnt++;
            }
            if (cnt!=k)continue;
            for (int i=1;i<=n;i++)l[i]=1e9;
            for (int j=1;j<=n;j++){
                if ((i>>j-1)&1)q.push(j),l[j]=0;
            }
            bfs();
            int ans=0;
            for (int i=1;i<=n;i++)ans=max(ans,l[i]);
            res=min(res,ans);
        }
        cout<<res<<"\n";
    }
    return 0;
}
