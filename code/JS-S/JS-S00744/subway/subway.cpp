#include <bits/stdc++.h>

using namespace std;

long long c,n,m,d,q,w[500005],k,a,t,x,y,ans,cst[505][505],pos;

vector<long long>sta_l[500005],sta_t[500005],l_l[505];
queue<long long>lne1,lne2;

void dijistra(){
    while(!lne1.empty()){
        int u=lne1.front(),v=lne2.front();
        lne1.pop();
        lne2.pop();
        for(long long i=0;i<l_l[v].size();i++){
            if(cst[u][l_l[v][i]]>cst[u][v]+cst[v][l_l[v][i]]){
                cst[u][l_l[v][i]]=cst[u][v]+cst[v][l_l[v][i]];
                lne1.push(u);
                lne2.push(l_l[v][i]);
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=0;i<m;i++){
        cin>>w[i];
    }
    for(long long i=0;i<n;i++){
        cin>>k;
        for(long long j=0;j<k;j++){
            cin>>a>>t;
            sta_l[a].push_back(i); //sta_l[station][]=line
            sta_t[a].push_back(t); //sta_t[station][]=time
        }
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            cst[i][j]=1e18;
        }
    }
    for(long long i=0;i<q;i++){
        for(long long j=0;j<m;j++){
            if(sta_l[j].size()>1){
                for(long long k1=0;k1<sta_l[j].size();k1++){
                    for(long long k2=k1+1;k2<sta_l[j].size();k2++){
                        if(j!=x&&find(sta_l[x].begin(),sta_l[x].end(),sta_l[j][k1])!=sta_l[x].end()){
                            for(int l=0;l<sta_l[x].size();l++){
                                if(sta_l[x][l]==sta_l[j][k1]){
                                    pos=l;
                                    break;
                                }
                            }
                            cst[sta_l[j][k1]][sta_l[k][k2]]=sta_t[j][k1]+sta_t[j][k2]+sta_t[x][pos];
                        }
                        else{
                           cst[sta_l[j][k1]][sta_l[k][k2]]=min(cst[sta_l[j][k1]][sta_l[j][k2]],sta_t[j][k1]+sta_t[j][k2]);
                        }
                        if(j!=y&&find(sta_l[y].begin(),sta_l[y].end(),sta_l[y][k2])!=sta_l[y].end()){
                            for(int l=0;l<sta_l[y].size();l++){
                                if(sta_l[y][l]==sta_l[j][k1]){
                                    pos=l;
                                    break;
                                }
                            }
                            cst[sta_l[j][k1]][sta_l[k][k2]]=sta_t[j][k1]+sta_t[j][k2]+sta_t[y][pos];
                        }
                        else{
                           cst[sta_l[j][k1]][sta_l[k][k2]]=min(cst[sta_l[j][k1]][sta_l[j][k2]],sta_t[j][k1]+sta_t[j][k2]);
                        }

                        l_l[sta_l[j][k1]].push_back(sta_l[j][k2]);
                        lne1.push(sta_l[j][k1]);
                        lne2.push(sta_l[j][k2]);
                        cst[sta_l[j][k2]][sta_l[j][k1]]=min(cst[sta_l[j][k2]][sta_l[j][k1]],sta_t[j][k1]+sta_t[j][k2]);
                        l_l[sta_l[j][k2]].push_back(sta_l[j][k1]);
                        lne1.push(sta_l[j][k2]);
                        lne2.push(sta_l[j][k1]);
                    }
                }
            }
        }
        for(long long j=0;j<sta_l[x].size();j++){
            for(long long l=0;l<n;l++){
                cst[sta_l[x][j]][l]+=sta_t[x][j];
            }
        }
        for(long long j=0;j<sta_l[y].size();j++){
            for(long long l=0;l<n;l++){
                cst[sta_l[y][j]][l]+=sta_t[y][j];
            }
        }
        dijistra();
        long long mi=1e18;
        ans=w[x]+w[y];
        for(long long j=0;j<sta_l[x].size();j++){
            for(long long l=0;l<sta_l[y].size();l++){
                mi=min(mi,cst[sta_l[x][j]][sta_l[y][l]]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
