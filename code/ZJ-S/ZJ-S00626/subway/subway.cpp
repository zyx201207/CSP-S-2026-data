#include<bits/stdc++.h>
using namespace std;
long long n,m,q,x,y,z,a[505][505],w[500005],ans;
vector<long long>d[500005],e[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>x>>n>>m>>x>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=1;j<=x;j++){
            cin>>y>>z;
            d[y].push_back(i);
            e[y].push_back(z);
        }
        for(int j=1;j<=n;j++)a[i][j]=999999999999999999ll;
        a[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<d[i].size();j++){
            for(int k=0;k<d[i].size();k++){
                a[d[i][j]][d[i][k]]=min(a[d[i][j]][d[i][k]],e[i][j]+e[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        ans=999999999999999999ll;
        for(int i=0;i<d[x].size();i++){
            for(int j=0;j<d[y].size();j++){
                ans=min(ans,a[d[x][i]][d[y][j]]+e[x][i]+e[y][j]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
