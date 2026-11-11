#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505];
vector<int>a;
vector<int>t;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a.push_back(x);
            t.push_back(y);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<y-x+1<<'\n';
    }
    return 0;
}
