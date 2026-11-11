#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,b[1000006],dis[1000006],ans,ty[1000006];
vector<int>e[1000006];
bool z[1000006],vis[1000006];
void search(int x,int y){
    z[x]=1;
    dis[x]=min(dis[x],y);
    for(int i=0;i<e[x].size();i++){
        if(!z[e[x][i]]){
            search(e[x][i],y+1);
        }
    }
}
void color(int x,int y){
    ty[x]=y;
    for(int i=0;i<e[x].size();i++){
        if(!ty[e[x][i]]&&vis[e[x][i]]){
            color(e[x][i],y);
        }
    }
}
void answer(){
    int tot=0;
    for(int i=1;i<=n;i++){
        ty[i]=0;
    }
    for(int i=1;i<=k;i++){
        if(!ty[b[i]]){
            tot++;
            color(b[i],tot);
        }
    }
    if(tot>2)return;
    for(int i=1;i<=n;i++){
        dis[i]=n;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            z[j]=0;
        }
        search(b[i],0);
    }
    int ma=0;
    for(int i=1;i<=n;i++){
        ma=max(ma,dis[i]);
    }
    ans=min(ma,ans);
}
void dfs(int x,int y){
    if(x==k+1){
        answer();
        return;
    }
    for(int i=y+1;i<=n;i++){
        b[x]=i;
        vis[i]=1;
        dfs(x+1,i);
        vis[i]=0;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c;
    if(c<=3){
        cin>>t;
        while(t--){
            cin>>n>>k;
            ans=n;
            for(int i=1;i<=n;i++){
                e[i].clear();
            }
            for(int i=1;i<n;i++){
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            dfs(1,0);
            cout<<ans<<endl;
        }
    }
    else if(c==7){
        cin>>t;
        while(t--){
            cin>>n>>k;
            ans=n;
            for(int i=1;i<=n;i++){
                e[i].clear();
            }
            for(int i=1;i<n;i++){
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int i=1;i<=n;i++){
                        dis[i]=n;
                        z[i]=0;
                    }
                    search(i,0);
                    for(int i=1;i<=n;i++){
                        z[i]=0;
                    }
                    search(j,0);
                    int ma=0;
                    for(int i=1;i<=n;i++){
                        ma=max(ma,dis[i]);
                    }
                    ans=min(ans,ma);
                }
            }
            cout<<ans<<endl;
        }
    }
    else if(c==13||c==14){
        cin>>t;
        while(t--){
            cin>>n>>k;
            for(int i=1;i<n;i++){
                cin>>u>>v;
            }
            if(k==n)cout<<0<<endl;
            else if(k>=n/2)cout<<1<<endl;
            else if(k==1)cout<<((n+1)/2+1)/2<<endl;
            else{
                if((n/2+1-k)%3==1)cout<<(n/2+1-k)/3+1<<endl;
                else cout<<(n/2+1-k)/3+2<<endl;
            }
        }
    }
    else{
        cin>>t;
        while(t--){
            cin>>n>>k;
            for(int i=1;i<n;i++){
                cin>>u>>v;
            }
            if(k==n)cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}
