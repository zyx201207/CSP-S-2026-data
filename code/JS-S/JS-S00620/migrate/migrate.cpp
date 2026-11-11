#include<bits/stdc++.h>
#define int long long
#define d first
#define v second
using namespace std;
typedef pair<int,int> pii;
const int N=5e3+7,N2=2e6+7;
int c,t,n,dd,cnt;
int a[N2],dis[N][N][3];
vector<int> p[N];
priority_queue<pii,vector<pii>,greater<pii> > q,emt;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>dd;
        cnt=0;
        bool flg=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i!=1&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
                flg=0;
            }
        }
        if(flg==1){
            if(a[2]-a[1]>=dd&&a[2]-a[1]<2*dd) cout<<n-2<<'\n';
            else cout<<"0\n";
            continue;
        }
        for(int i=1;i<=n;i++) p[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=dd){
                    p[i].push_back(j);
                    p[j].push_back(i);
                }else break;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=0;k<=2;k++) dis[i][j][k]=1e18;
        for(int i=1;i<=n;i++){
            q=emt;
            dis[i][i][0]=0;
            q.push({0,i});
            while(!q.empty()){
                int u=q.top().v,d=q.top().d;
                q.pop();
                for(auto v:p[u]){
                    int nd=d+1;
                    if(dis[i][v][0]>=nd){
                        dis[i][v][2]=dis[i][v][1];
                        dis[i][v][1]=dis[i][v][0];
                        dis[i][v][0]=nd;
                        q.push({nd,v});
                    }else if(dis[i][v][1]>=nd){
                        dis[i][v][2]=dis[i][v][1];
                        dis[i][v][1]=nd;
                        q.push({nd,v});
                    }else if(dis[i][v][2]>=nd){
                        dis[i][v][2]=nd;
                        q.push({nd,v});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dis[i][j][0]==dis[i][j][1]&&dis[i][j][2]>dis[i][j][1])
                    cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
