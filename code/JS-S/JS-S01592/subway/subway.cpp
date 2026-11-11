#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5001],a[5001][5001],k[5001];
vector<int>p[5001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[j];j++){
            int aa,bb;
            cin>>aa>>bb;
            p[0][0]=bb;
        }
    }
    int x=0,y=0;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<4*p[0][0]+w[x]+w[y]<<endl;
    }
    return 0;
}
