#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
vector<node> a[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        a[i].push_back({i+n,x});
    }
    for(int i=1;i<=n;i++){
        int k,t[500005];
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>t[i];
            a[2*n+i].push_back({t[i],0});
        }
        for(int i=1;i<=k;i++){
            int x;
            cin>>x;
            a[t[i]+n].push_back({2*n+i,x});
        }
    }
    return 0;
}
