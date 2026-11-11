#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
long long xianlu[501][50001];
long long w[1001000];//地铁口走到站厅需要的时间
vector<pair<long long,long long> > zhanting[1001000];
long long a[10010][10010];
void solve(){
    cin>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++) cin>>w[i];
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            cin>>xianlu[i][j];
            if(j>1&&a[xianlu[i][j]][xianlu[i][j-1]]==1000000000){
                a[xianlu[i][j]][xianlu[i][j-1]]=(long long)0;
                a[xianlu[i][j-1]][xianlu[i][j]]=(long long)0;
            }
            long long t;
            cin>>t;
            zhanting[xianlu[i][j]].push_back({i,t});
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=0;j<zhanting[i].size()-1;j++){
            for(long long k=j+1;k<zhanting[i].size();k++){
                a[zhanting[i][j].first][zhanting[i][k].first]=zhanting[i][j].second+zhanting[i][k].second;
                a[zhanting[i][k].first][zhanting[i][j].first]=a[zhanting[i][j].first][zhanting[i][k].first];
                //cout<<zhanting[i][j].first<<" "<<zhanting[i][k].first<<" "<<a[zhanting[i][j].first][zhanting[i][k].first]<<endl;
            }
        }
    }
    for(long long k=1;k<=m;k++){
        for(long long i=1;i<=m;i++){
            for(long long j=1;j<=m;j++){
                if(a[i][k]==-1||a[k][j]==-1) continue;
                a[i][j]=min(min(a[i][j],a[j][i]),a[i][k]+a[k][j]);
                //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        long long sum=w[x]+w[y];
        //cout<<sum<<endl;
        long long minn=1000000000;
        for(long long i=0;i<zhanting[x].size();i++){
            for(long long j=0;j<zhanting[y].size();j++){
                minn=min(minn,a[zhanting[x][i].first][zhanting[y][j].first]+zhanting[x][i].second+zhanting[y][j].second);
                //cout<<a[zhanting[x][i].first][zhanting[y][j].first]<<" "<<zhanting[x][i].second<<" "<<zhanting[y][j].second<<endl;
            }
        }
        cout<<sum+minn<<endl;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    if(c==0) c=1;
    while(c--){
        for(long long i=1;i<=10009;i++){
            for(long long j=1;j<=10009;j++){
                if(i==j) a[i][j]=0;
                else a[i][j]=1000000000;
            }
        }
        for(int i=1;i<=500;i++){
            for(int j=1;j<=50000;j++){
                xianlu[i][j]=0;
            }
        }
        for(int i=0;i<=1000001;i++){
            while(!zhanting[i].empty()) zhanting[i].pop_back();
        }
        solve();
    }
    return 0;
}
