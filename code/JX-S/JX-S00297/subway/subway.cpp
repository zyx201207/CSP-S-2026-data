#include<bits/stdc++.h>
using namespace std;
int w[510];
vector<vector<int>> v;
void bfs(int st,int fi){
    for(int i=1;i<=v[st].size();i++){

    }
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=q;i++){
        int st,fi;
        cin>>st>>fi;
        bfs(st,fi);
    }
    return 0;
}
