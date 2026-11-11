#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[2000];
long long l[1503][1503];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
       // cout<<i<<" "<<w[i]<<endl;
    }
    for(int i=1;i<=1501;i++){
        for(int j=1;j<=1501;j++){
            l[i][j]=100000000000;
            if(i==j) l[i][j]=0;
        }
        //cout<<w[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            l[a][m+i]=t;
            l[m+i][a]=t;
        }
    }

    for(int k=1;k<=m+n;k++){
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+l[x][y]<<endl;
    }
    return 0;

}
