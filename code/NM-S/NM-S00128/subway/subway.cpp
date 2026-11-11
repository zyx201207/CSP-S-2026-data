#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5010,M=510,INF=0x3f3f3f3f3f3f3f3f;
LL li[M][N],c,n,m,q,st[N];
int k[M];
vector<int>dot[N];
vector<int>md;
LL d[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>c>>q;
    for(int i=0;i<m;i++)cin>>st[i];
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0,x;j<k[i];j++){
            cin>>x>>li[i][x];
            dot[x].push_back(i);
            if(dot[x].size()>1)md.push_back(x);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<dot[i].size();j++){
                for(int i1=0;i1<m;i1++){
                        if(i==i1)continue;
                        for(int j1=0;j1<dot[i1].size();j1++){
                            if(dot[i][j]==dot[i1][j1])d[i][i1]=d[i1][i]=li[dot[i][j]][i]+li[dot[i][j]][i1];
                        }

                }
        }
    }
    for(int i=0;i<md.size();i++){
        for(int j=0;j<dot[md[i]].size();j++){
                int li1=dot[md[i]][j];
            for(int j1=0;j1<dot[md[i]].size();j1++){
                int li2=dot[md[i]][j1];
                for(int di=0;di<m;di++){
                    for(int di1=0;di1<m;di1++){
                        if(li[li1][di]&&li[li2][di1])d[di][di1]=d[di1][di]=(d[di][i]+d[di1][i]);
                    }
                }

            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        LL ans=st[x]+st[y];
        cout<<(ans+d[x][y])<<endl;
    }
}
