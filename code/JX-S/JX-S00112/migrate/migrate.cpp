#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,rN=2e6+10;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,x[rN],f[N],vis[N],in[N];
vector<int> G[N],H[N];
void bfs(int start){
    queue<int> q;
    q.push(start);
    vis[start]=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto ne:G[t]){
            if(vis[ne]>vis[t]+1){
                vis[ne]=vis[t]+1;
                q.push(ne);
            }
        }
    }
}
void topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            f[i]=1;
            q.push(i);
        }
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto ne:H[t]){
            in[ne]--;
            f[ne]+=f[t];
            if(in[ne]==0) q.push(ne);
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    if(c<=10){
        while(T--){
            int ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
                G[i].clear();
            }
            for(int i=1;i<=n;i++){
                for(int j=i-1;j>=1;j--){
                    if(x[i]-x[j]<=d){
                        G[i].push_back(j);
                    }
                    else break;
                }
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]<=d){
                        G[i].push_back(j);
                    }
                    else break;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    f[j]=0;
                    vis[j]=inf;
                    in[j]=0;
                    H[j].clear();

                }
                bfs(i);
                for(int i=1;i<=n;i++){
                    for(auto ne:G[i]){
                        if(vis[i]+1==vis[ne]){
                            H[i].push_back(ne);
                            in[ne]++;
                        }
                    }
                }
                topsort();
                for(int i=1;i<=n;i++) if(f[i]==2) ans++;
            }
            cout<<ans/2<<'\n';
        }
        return 0;
    }
    else{
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            int ans=0;
            int cf=inf;
            bool flagA=true;
            for(int i=2;i<=n;i++){
                if(cf==inf) cf=x[i]-x[i-1];
                else if(x[i]-x[i-1]!=cf){
                    flagA=false;
                    break;
                }
            }
            if(flagA){
                for(int i=1;i<n;i++){
                    int l=i,r=n,id=i;
                    while(l<=r){
                        int mid=l+r>>1;
                        if(x[mid]-x[i]<=d) l=mid+1,id=mid;
                        else r=mid-1;
                    }
                    if(l==i||id==n) continue;
                    int len=id-i;
                    if(id+len-1<=n) ans++;
                }
                cout<<ans<<'\n';
            }
            else cout<<0<<'\n';
        }
    }
    return 0;
}
