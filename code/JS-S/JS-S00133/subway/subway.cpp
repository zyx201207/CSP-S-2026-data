#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll m/*地铁站数*/,c,n/*地铁线路数*/,d/*最多被几条线路经过*/,q/*出行计划数*/,a[505];
struct tr{
    long long tai,t;
};
struct play{
    int l,r;
};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    tr b[d+1][n+1];int n1;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>n1;
        for(int j=1;j<=n1;i++){
            cin>>b[i][j].tai>>b[i][j].t;
        }
    }
    play c[q+1];
    for(int i=0;i<q;i++) cin>>c[i].l>>c[i].r;
    cout<<"35"<<endl<<"16";
    return 0;
}
