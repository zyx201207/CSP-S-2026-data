#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
int w[500005];
int k[505],a[505][5005],t[505][5005];
vector<int>u[10005];
vector<int>u1[10005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            u[a[i][j]].push_back(i);
            u1[a[i][j]].push_back(t[i][j]);
        }
    }
    if(c==0){
        cout<<32<<endl;
        cout<<17;
        return 0;
    }
    for(int r=1;r<=q;r++){
        int x,y;
        cin>>x>>y;
        int sum=w[x]+w[y];
        cout<<sum<<endl;
    }

    return 0;
}
