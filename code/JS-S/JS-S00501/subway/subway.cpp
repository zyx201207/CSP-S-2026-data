#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int w[500010],k[505];
vector<int> a[505];
vector<int> t[505];
vector<pair<int,int> > ps[500010];
int f[505][505];

 
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            ps[x].push_back({i,y});            
        }
        for(int j=1;j<=n;j++){
            f[i][j]=1e17+7;
        }
    }

    for(int i=1;i<=m;i++){
        for(pair<int,int> j:ps[i]){
            for(pair<int,int> k:ps[i]){
                if(j.first==k.first)continue;
                f[j.first][k.first]=min(f[j.first][k.first],j.second+k.second);
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(k==i||k==j||i==j)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                f[j][i]=f[i][j];
            }
        }
    }
    
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        int minn=LONG_LONG_MAX;
        for(pair<int,int> i:ps[x]){
            for(pair<int,int> j:ps[y]){
                if(i.first==j.first){
                    minn=min(minn,w[x]+w[y]+i.second+j.second);
                }
                else{
                    minn=min(minn,f[i.first][j.first]+w[x]+w[y]+i.second+j.second);
                }
            }
        }
        cout<<minn<<'\n';
    }

}