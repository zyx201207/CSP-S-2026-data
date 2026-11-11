#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
using ll=long long;

int c,t,n,k;
int picked[50];
int dis[maxn],dis2[maxn];

int cur,cnt;

vector<int>s1_g[20];

void check(int u,int p){
    dis[u]=dis2[u]=100;
    if(picked[p]==0&&picked[u]==1)cnt++;
    if(picked[u]==1)dis[u]=dis2[u]=0;
    dis[u]=min(dis[u],dis[p]+1);
    for(int v:s1_g[u]){
        if(v==p)continue;
        check(v,u);
        dis2[u]=min(dis2[u],dis2[v]+1);
    }

}

void solv1(){
    for(int i=1;i<=n;i++){
        s1_g[i].erase(s1_g[i].begin(),s1_g[i].end());
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        s1_g[u].push_back(v);
        s1_g[v].push_back(u);
    }
    int ans=2000;
    for(int i=1;i<=(1<<n)-1;i++){
        if(__builtin_popcount(i)!=k)continue;
        int tmp=i;
        for(int j=1;j<=n;j++){
            picked[j]=tmp&1;
            tmp>>=1;
        }
        cnt=0,cur=0;
        check(1,0);
        if(cnt<=2){
            for(int i=1;i<=n;i++){
                dis[i]=min(dis[i],dis2[i]);
                cur=max(cur,dis[i]);
            }
            ans=min(ans,cur);
        }
    }
    cout<<ans<<endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        if(n<=10)solv1();
    }

    return 0;
}
