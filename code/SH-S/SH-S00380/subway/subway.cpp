#include<bits/stdc++.h>
using namespace std;
const long long MAXM=500005,INF=4e18;
long long c,n,m,d,q,w[MAXM],dist[505][505];
vector<vector<pair<int,long long> > > ltos;
vector<vector<pair<int,long long> > > sta;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>n>>m>>d>>q;
    ltos.resize(n+1);
    sta.resize(m+1);
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=0;j<k;++j){
            int a,t;
            cin>>a>>t;
            ltos[i].push_back(make_pair(a,t));
            sta[a].push_back(make_pair(i,t));

        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j){dist[i][i]=0;}
            else{
                dist[i][j]=INF;
            }
        }
    }
    /*for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            cout<<"dist ("<<k<<","<<i<<")="<<dist[k][n]<<endl;
        }
    }*/
    for(auto lines : sta){
        int len=lines.size();
        for(int i=0;i<len;++i){
            for(int j=i+1;j<len;++j){
                dist[lines[j].first][lines[i].first]=dist[lines[i].first][lines[j].first]=min(dist[lines[i].first][lines[j].first],lines[i].second+lines[j].second);
            }
        }
    }

    //floyd
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }



    for(int i=1;i<=q;++i){
        long long xr,yr,ans=INF;
        cin>>xr>>yr;
        for(auto l1 : sta[xr]){
            for(auto l2 : sta[yr]){
                ans=min(ans,dist[l1.first][l2.first]+l1.second+l2.second);
            }
        }
        cout<<ans+w[xr]+w[yr]<<"\n";
    }
    return 0;
}