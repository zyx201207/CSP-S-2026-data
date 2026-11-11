#include<bits/stdc++.h>
using namespace std;
long long n,i,j,q,m,k,C,t,d,a[500005],b[505][505],x,y;
vector<pair<long long,long long>> c[500005];
long long minn(long long a,long long b){
    if(a<=b)return a;
    return b;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(i=0;i<m;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[i][j]=1000000000000000000;
    for(i=0;i<n;i++)
        b[i][i]=0;
    for(i=0;i<n;i++){
        cin>>k;
        for(j=0;j<k;j++){
            cin>>C>>t;
            c[C].push_back(make_pair(i,t));
        }
    }
    for(i=1;i<=m;i++){
        for(j=0;j<c[i].size()-1;j++)
            for(k=j+1;k<c[i].size();k++){
                b[c[i][k].first][c[i][j].first]=minn(b[c[i][k].first][c[i][j].first],c[i][j].second+c[i][k].second);
                b[c[i][j].first][c[i][k].first]=minn(b[c[i][j].first][c[i][k].first],c[i][j].second+c[i][k].second);
            }
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++){
                b[j][k]=minn(b[j][k],b[j][i]+b[i][k]);
                b[k][j]=b[j][k];
    }
    for(;q>0;q--){
        cin>>x>>y;
        t=2000000000000000000;
        for(i=0;i<c[x].size();i++)
            for(j=0;j<c[y].size();j++){
                t=minn(t,c[x][i].second+c[y][j].second+b[c[x][i].first][c[y][j].first]);
            }
        t=t+a[x-1]+a[y-1];
        cout<<t<<endl;
    }
    return 0;
}
