#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    //测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
    vector<int> w(m+1);//站台到站厅
    vector<vector<pair<int,int> > > ma(m+1,vector<pair<int,int> >(d+1,{0,0}));
    vector<int> h(m+1,0);//途经线数量
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int kt;//途径站点数量
        cin>>kt;
        for(int j=1;j<=kt;j++){
            int a;
            long long t;
            cin>>a>>t;//途径站，站厅到站台时间
            h[a]=h[a]+1;
            ma[a][h[a]]={i,t};
        }
    }

    vector<vector<long long>> mb(n+1,vector<long long>(n+1,-1));

    for(int i=1;i<=m;i++){
        for(int x=1;x<=h[i];x++){
            for(int y=1;y<=h[i];y++){
                if(x==y)continue;
                int a=ma[i][x].first;
                long long ta=ma[i][x].second;
                int b=ma[i][y].first;
                long long tb=ma[i][y].second;

                if(mb[a][b]==-1)mb[a][b]=ta+tb;
                else mb[a][b]=min(mb[a][b],ta+tb);

            }
        }
    }
    for(int i=1;i<=n;i++){
        mb[i][i]=0;
    }
    for(int t=1;t<=n;t++){
        for(int x=1;x<=n;x++){
            if(mb[x][t]==-1)continue;
            for(int y=1;y<=n;y++){
                if(mb[t][y]==-1)continue;
                if(mb[x][y]!=-1)mb[x][y]=min(mb[x][y],mb[x][t]+mb[t][y]);
                else if(mb[x][y]==-1)mb[x][y]=mb[x][t]+mb[t][y];
            }
        }
    }

    while(q--){
        int s,t;
        cin>>s>>t;

        long long ans=-1;
        for(int x=1;x<=h[s];x++){
            for(int y=1;y<=h[t];y++){
                int a=ma[s][x].first;
                int b=ma[t][y].first;
                if(mb[a][b]!=-1){
                    long long ta=ma[s][x].second;
                    long long tb=ma[t][y].second;
                    if(ans>ta+tb+mb[a][b]||ans==-1){
                        ans=ta+tb+mb[a][b];
                        //cout<<a<<' '<<b<<' '<<ta<<' '<<tb<<' '<<mb[a][b]<<' '<<ans<<endl;
                    }
                }

            }

        }
        ans=ans+w[s]+w[t];
        cout<<ans<<"\n";
    }
    return 0;
}
