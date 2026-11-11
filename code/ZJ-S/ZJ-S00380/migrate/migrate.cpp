#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace YJR{
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int T,n,lst[2000005],d,ans,dis[2000005],cnt[2000005];
bool vis[2000005];
priority_queue<int,vector<int>,greater<int>> q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(),T=read();
    while(T--){
        n=read(),d=read();
        for(int i=1;i<=n;i++) lst[i]=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dis[j]=1e18,cnt[j]=1,vis[j]=0; 
            q.push(i);vis[i]=1;dis[i]=0;
            while(!q.empty()){
                int now=q.top();
                q.pop();vis[now]=0;
                if(cnt[now]>2) continue;
                for(int j=now+1;j<=n;j++){
                    if(lst[j]-lst[now]>d) break;
                    if(dis[j]==dis[now]+1){
                        cnt[j]+=cnt[now];
                    }
                    if(dis[j]>dis[now]+1){
                        cnt[j]=cnt[now];
                        dis[j]=dis[now]+1;
                        if(!vis[j]) q.push(j),vis[j]=1;
                    }
                }
            }
            for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
            // for(int j=1;j<=n;j++) if(cnt[j]==2){
            //     cerr<<i<<' '<<j<<endl;
            // }
        }
        cout<<ans<<endl;
        ans=0;
    }
    // cerr<<clock()*1.0/CLK_TCK;
    return 0;
}
}

signed main(){return YJR::main();}
//g++ migrate.cpp -o migrate -O2 -std=c++14 -static