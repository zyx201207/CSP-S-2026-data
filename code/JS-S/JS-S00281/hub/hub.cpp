/*
I don't know how it feels.
I have two friends,who I play with them very well from the age of 6.A boy and a girl.
For some reason,we didn't connect as frequently as before ,as we were in different classes.
After coming into senior high.we connect much more.
Days before ,the boy became the girl's boyfriend.As his sincere friend,I feel absolutely happy.
Thus,they come much closer.Only I,like a boat missing in the sea,not knowing what to depend on.
Sure,I don't feel jealousy about their delight.
But I am...,just a little lonely.



*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int fa[500050],d[15][15];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>g[n+1];
    map<pair<int,int>,bool>mp;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u,v}]=mp[{v,u}]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=d[j][i]=1e16;
        }
    }
    for(int i=1;i<=n;i++){
        for(auto e:g[i]){
            d[i][e]=d[e][i]=1;
        }
    }
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==k||j==k)continue;
                d[j][i]=d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int minx=1e16;
    for(int i=1;i<=(1<<n);i++){
        int cnt=0,x=i;
        while(x){
            cnt+=(x&1);
            x>>=1;
        }
        if(cnt!=k)continue;
        x=i;int t=0;
        vector<int>v(0);
        while(x){
            t++;
            if(x&1)v.push_back(i);
        }
        for(int i=1;i<=k;i++)fa[i]=i;
        int p=k;
        for(int j=1;j<=k;j++){
            for(int l=1;l<j;l++){
                if(mp[{v[j],v[i]}]){
                    int l1=find(v[j]),l2=find(v[i]);
                    if(l1!=l2){
                        fa[l1]=l2;
                        p--;
                    }
                }
            }
        }
        if(p>2)continue;
        int ans=0;
        for(int j=1;j<=n;j++){
            int minn=1e16;
            for(int l=1;l<=k;l++){
                minn=min(minn,d[j][v[k]]);
            }
            ans=max(ans,minn);
        }
        minx=min(minx,ans);
    }
    cout<<minx<<endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;cin>>c>>t;
    while(t--)solve();
    return 0;
}












