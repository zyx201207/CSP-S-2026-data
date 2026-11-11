#include<bits/stdc++.h>
using namespace std;

int main(){

    int c,n,d;
    long long m,q;
    cin>>c>>n>>m>>d>>q;

    long long w[500010];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    long long z[30],a[500][30],t[500][30];
    for(int i=1;i<=n;i++){
        cin>>z[i];
        for(int j=1;j<=z[i];j++){
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }

    long long xy[100010],x[100010],y[100010];
    for(int i=1;i<=q;i++){
        cin>>x[i];
        cin>>y[i];
    }

    long long time[100010];
    for(int i=1;i<=q;i++){
        time[i]=w[x[i]]+w[y[i]];
    }

    for(int i=1;i<=q;i++){
        cout<<time[i]<<endl;
    }

    return 0;
}
