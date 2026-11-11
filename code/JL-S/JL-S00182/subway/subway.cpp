#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,p;
vector<int> tim;
struct Node{
    int x,t;
};
int line[510];
vector<vector<Node> > mapa;


int x,y;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;

    tim.resize(m);
    for(int i=1;i<=m;i++){
        cin>>tim[i];
    }

    mapa.resize(n);
    for(int i=1;i<=n;i++){
        cin>>line[i];
        mapa[i].resize(line[i]);
        for(int j=1;j<line[i];j++)
            cin>>mapa[i][j].x>>mapa[i][j].t;
    }

    for(int i=1;i<=n;i++){
        cin>>x>>y;
        cout<<tim[x]+tim[y];
    }
    return 0;
}
