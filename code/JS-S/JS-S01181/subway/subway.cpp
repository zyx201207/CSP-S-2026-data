#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=5e5+5;
ll c,n,m,d,q,k,fa;
ll w[_],a[_],t[505][_],x,y;
vector<ll> v[_];
ll ds[7745][7745],fl[7745][7745];
int main(){
    freopen("subway.in","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    freopen("subway.out","w",stdout);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(ds,0x3f,sizeof(ds));
    for(int p=1;p<=n;p++){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i]>>t[p][i];
            if(i==1){
                fa=a[i];
                continue;
            }
            ds[a[i]][fa]=ds[a[i]][fa]=0;
            fl[a[i]][fa]=fl[fa][a[i]]=p;
            v[a[i]].push_back(fa);
            v[fa].push_back(a[i]);
            fa=a[i];
        }
    }
    for(int p=1;p<=m;p++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                ll sp=0;
                if(fl[i][p]!=fl[p][j]){
                    sp=t[fl[i][p]][p]+t[fl[p][j]][p];
                }
                ds[i][j]=min(ds[i][p]+ds[p][j]+sp,ds[i][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<ds[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
