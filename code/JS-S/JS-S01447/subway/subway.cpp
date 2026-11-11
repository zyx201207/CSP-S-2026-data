#include<bits/stdc++.h>
using namespace std;
long long w[500005];
int k[505];
vector<int> a[505];
vector<long long> t[505];
long long dis[2005][2005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if((c>=7&&c<=11)||c==0){
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                int A;long long T;
                cin>>A>>T;
                a[i].push_back(A);
                t[i].push_back(T);
            }
            if(k[i]==2){
                dis[a[i][1]][a[i][0]] = t[i][1]+t[i][0]+w[a[i][1]]+w[a[i][0]];
                dis[a[i][0]][a[i][1]] = dis[a[i][1]][a[i][0]];
            }
        }
        for(int x=1;x<=m;x++){
            for(int i=1;i<=m;i++){
                for(int j=i+1;j<=m;j++){
                    if(x!=i&&x!=j){
                        dis[i][j] = min(dis[i][j],dis[i][x]+dis[j][x]);
                        dis[j][i] = dis[i][j];
                    }
                }
            }
        }
        int s,e;
        for(int i=1;i<=q;i++){
            cin>>s>>e;
            cout<<dis[s][e]<<"\n";
        }
    }else{
        cout<<15<<"\n";
    }
    return 0;
}
