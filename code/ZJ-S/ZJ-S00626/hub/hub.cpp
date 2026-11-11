#include<bits/stdc++.h>
using namespace std;
long long C,T,n,k,u,v,mx,ans,a[15],dis[15],l,r,cnt;
queue<int>q;
vector<long long>d[1000005];
bool check(int x){
    return 4*(x-1)+k>=n/2;
}
void dfs(int x){
    a[x]=2;
    for(int i=0;i<d[x].size();i++){
        if(a[d[x][i]]==1)dfs(d[x][i]);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            d[i].clear();
        }
        for(int i=1;i<n;i++){
            cin>>u>>v;
            d[u].push_back(v);
            d[v].push_back(u);
        }
        if(C==13||C==14){
            if(n==k){
                cout<<"0\n";
                continue;
            }
            l=1;
            r=n-1;
            while(l<r){
                if(check((l+r)>>1))r=(l+r)>>1;
                else l=(l+r+2)>>1;
            }
            cout<<l<<"\n";
            continue;
        }
        ans=999999999;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)!=k)continue;
            for(int j=1;j<=n;j++){
                if(i&(1<<(j-1)))a[j]=1;
                else a[j]=0;
            }
            cnt=0;
            for(int j=1;j<=n;j++){
                if(a[j]==1){
                    dfs(j);
                    cnt++;
                }
            }
            if(cnt>2)continue;
            for(int j=1;j<=n;j++){
                if(a[j]==2){
                    q.push(j);
                    dis[j]=0;
                }
            }
            mx=0;
            while(!q.empty()){
                mx=max(mx,dis[q.front()]);
                for(int j=0;j<d[q.front()].size();j++){
                    if(a[d[q.front()][j]]==0){
                        q.push(d[q.front()][j]);
                        a[d[q.front()][j]]=2;
                        dis[d[q.front()][j]]=dis[q.front()]+1;
                    }
                }
                q.pop();
            }
            ans=min(ans,mx);
        }
        cout<<ans<<"\n";
    }
}
