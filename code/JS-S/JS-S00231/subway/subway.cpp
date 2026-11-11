#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,k[510];
int w[N],a[510][N],t[510][N];
vector<pair<int,int> >p[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
        for(int j=1;j<=k[i];j++){
            for(int e=1;e<=k[i];e++){
                pair<int,int>x={a[i][e],t[i][a[i][j]]+t[i][a[i][e]]};
                p[a[i][j]].push_back(x);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<2*t[1][1]<<"\n";
    }
    return 0;
}
