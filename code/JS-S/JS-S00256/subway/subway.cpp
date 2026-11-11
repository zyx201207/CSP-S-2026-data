#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<pair<long long,long long> >k[501];
long long w[500001],a,t;
int main(){
    freopen(subway.in,"r",stdin);
    freopen(subway.out,"w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        while(ki--){
            cin>>a>>t;
            k[i].push_back(make_pair(a,t));
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    return 0;
}
