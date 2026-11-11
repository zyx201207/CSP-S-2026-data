#include<bits/stdc++.h>
using namespace std;
const int N=500005,Q=100005;
int c, n, m, d, q,w[N],tp[Q][2];

struct AT{
    int a,t;
}at[5005][5005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

    for(int i=0;i<m;i++){
        cin>>w[i];
    }

    for(int i=0;i<n;i++){
        cin>>at[i][0].t;
        for(int j=1;j<=at[i][0].t;j++){
            cin>>at[i][j].a>>at[i][j].t;
        }
    }

    for(int i=0;i<q;i++){
        cin>> tp[i][0] >> tp[i][1];
    }

    for(int i=0;i<q;i++){
        cout<< (w[tp[i][0]]+w[tp[i][1]]) <<endl;
    }

    return 0;
}

