#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=501000;

int c,n,m,d,q,a[N];
long long dis[510][510];

vector<pii> mp[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        int k; scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int v,w; scanf("%d%d",&v,&w);
            mp[i+m].push_back({v,w}),mp[v].push_back({i+m,w});
            for(pii temp:mp[v]){
                int sta=temp.first-m;
                long long len=temp.second;
                dis[i][sta]=min(dis[i][sta],len+w);
                dis[sta][i]=dis[i][sta];
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
    while(q--){
        int s,t; scanf("%d%d",&s,&t);
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(pii temp1:mp[s]){
            for(pii temp2:mp[t]){
                int s1=temp1.first-m,s2=temp2.first-m;
                long long w1=temp1.second,w2=temp2.second;
                ans=min(ans,dis[s1][s2]+w1+w2);
            }
        }
        cout<<ans+a[s]+a[t]<<endl;
    }
    return 0;
}