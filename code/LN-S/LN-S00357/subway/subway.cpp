#include <bits/stdc++.h>
using namespace std;


int main(){//floyd???
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;

    long long INF=0x3f3f3f3f3fLL;
    
    vector<long long> lobby_depth(m+1,INF);//d[i]:ith station's dist from platform 2 ground
    for(int i=1;i<=m;i++)cin>>lobby_depth[i];
    

    vector<vector<long long>> stations(m+1);//s[i]={p1,p2,p3....},ith station passed by line p;
    vector<vector<long long>> lines(n+1);//stations that line i able 2 pass;
    vector<vector<long long>> platform_depth(m+1,vector<long long>(n+1,INF));//pd[i][j]:ith lobby 2 line j's platform depth;
    vector<vector<vector<vector<long long>>>> paths(m+1,vector<vector<vector<long long>>>(m+1,vector<vector<long long>>(d,vector<long long>(d,INF))));
    //paths[f][t][stat_f][stat_t]

    for(int li=1;li<=n;li++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int sta,dept;cin>>sta>>dept;
            platform_depth[sta][li]=dept;
            stations[sta].push_back(li);
            lines[li].push_back(sta);
        }
        for(int f:lines[li]){
            for(int t:lines[li]){
                paths[f][t][li][li]=platform_depth[f][li]+platform_depth[t][li];
            }
        }

    }



    //floyd

    for(int k=1;k<=m;k++){//mid
        for(int stat_ok:stations[k]){//from~k stat
            for(int from:lines[stat_ok]){//from
                for(int stat_ik:stations[k]){//k~to stat
                    for(int to:lines[stat_ik]){//to
                        if(stat_ok!=stat_ik){
                            paths[from][to][stat_ok][stat_ik]=min(paths[from][to][stat_ok][stat_ik],
                                paths[from][k][stat_ok][stat_ok]+paths[k][to][stat_ik][stat_ik]
                            );
                        }
                    }
                }
            }
        }
    }

    for(int k=1;k<=m;k++){//mid
        for(int i=1;i<=m;i++){//from
            for(int j=1;j<=m;j++){//to
                for(int stat_f:stations[i]){
                    for(int stat_ok:stations[k]){
                        for(int stat_to:stations[j]){
                            for(int stat_ik:stations[k]){
                                if(stat_ok!=stat_ik){
                                    paths[i][j][stat_f][stat_to]=min(paths[i][j][stat_f][stat_to],
                                        paths[i][k][stat_f][stat_ok]+paths[k][j][stat_ik][stat_to]
                                    );
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    






    while(q--){
        int from,to;cin>>from>>to;
        long long base=lobby_depth[from]+lobby_depth[to];
        long long mini=INF;
        for(int sf:stations[from]){
            for(int st:stations[to]){
                if(paths[from][to][sf][st]!=INF)mini=min(mini,paths[from][to][sf][st]);
            }
        }
        cout<<mini+base<<'\n';
    }


    return 0;
}