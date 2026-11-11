#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000009],n,d;
vector<int> g[5009];
int vis[2000009];
map<int,int> cnt;
int l[2000009];
signed main(){
    int c,t;
    scanf("%lld %lld",&c,&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        cnt.clear();
        memset(l,0,sizeof(l));
        scanf("%lld %lld",&n,&d);
        for(int i = 1;i<=n;i++) scanf("%lld",&a[i]),g[i].clear();
        if(c<=10){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<i;j++){
                    if(a[i]-a[j] <= d) g[j].push_back(i),l[i]++;
                }
            }

            queue<int> pq;
            for(int i = 1;i<=n;i++){
                if(!l[i]) pq.push(i),vis[i] = 1;
            }
            while(pq.size()){
                int x = pq.front();
                printf("%lld %lld\n",x,cnt[x]);
                pq.pop();
                for(auto it:g[x]){
                    if(!vis[it]) vis[it] = vis[x]+1, cnt[it]++, pq.push(it);
                    else if(vis[it]==vis[x]+1) cnt[it]++;
                    else if(vis[it]<vis[x]+1&&cnt[it]<2) vis[it] = vis[x]+1,cnt[it]=1,pq.push(it);
                }
            }
            int ans = 0;
            for(int i = 1;i<=n;i++){
                if(cnt[i]==2) ans++;
            }
            printf("%lld\n",ans);
        }
    }
    
}