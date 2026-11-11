#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1000;
const int M=5e5+5;
vector<pair<int,int> > lines[MAXN];
ll t[M];
ll c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>t[i];
    if(7<=c&&c<=11){
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int i=1;i<=k;i++){
                int u,tt;
                cin>>u>>tt;
                lines[i].push_back({u,tt});
            }
        }

    }

}
