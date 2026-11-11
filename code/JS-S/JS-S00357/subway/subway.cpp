#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N],a[500][N],t[500][N];
vector<int> g1[N],g2[500];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
            g1[j].push_back(i);
            g2[i].push_back(j);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i:g1[x]){
            for(int j:g2[i]){
                if(j==x)continue;

            }
        }
    }

    return 0;
}
