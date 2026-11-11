#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=510;
int cnt;
int c,n,m,d,q,w[N],k[M],x[N],y[N];
int dis[N+M],ans[N];
bool boo[N+M];
vector<int> a[M+N],t[M+N];
priority_queue<pair<int,int> > qu;
void dijkstra(int s){
    for(int i=1;i<=n+m;i++) dis[i]=INT_MAX,boo[i]=false,cnt++;
    dis[s]=0;
    qu.push({0,s});
    while(qu.size()){
        int f=qu.top().second;
        //cout<<dis[f]<<"\n";
        qu.pop();
        if(f>m&&f<s) continue;
        //if(boo[f]==true) continue;
        //boo[f]=true;
        for(int i=0;i<a[f].size();i++){
            if(dis[a[f][i]]>dis[f]+t[f][i]){
                dis[a[f][i]]=dis[f]+t[f][i];
                qu.push({dis[a[f][i]],a[f][i]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=q;i++) ans[i]=INT_MAX;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int fcy,wyr;
            cin>>fcy>>wyr;
            a[i+m].push_back(fcy);t[i+m].push_back(wyr);
            a[fcy].push_back(i+m);t[fcy].push_back(wyr);
        }
    }
   // for(int j=1;j<=2000;j++){
    //    for(int i=1;i<=960000;i++) cnt++;
    //    cout<<cnt<<"\n";
    //}

    for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        dijkstra(i+m);

        //for(int j=1;j<=m;j++) cout<<dis[j]<<" ";
        //cout<<"\n";
        for(int p=1;p<=q;p++) ans[p]=min(ans[p],dis[x[p]]+dis[y[p]]);
    }

    for(int i=1;i<=q;i++) cout<<ans[i]+w[x[i]]+w[y[i]]<<"\n";
}

