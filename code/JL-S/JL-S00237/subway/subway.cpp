#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int a,b,c,d,e,w[100001],n[1000][1000],z[1000][1000],x[100001],y[100001],k[100001];
    cin>>a>>b>>c>>d>>e;
    for(int i=1;i<=c;i++){
        cin>>w[i];
    }
    for(int i=3;i<=b+2;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>n[i][j]>>z[i][j];
        }
    }
    for(int i=1;i<=e;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=e;i++){
        int v=x[w[x[i]]]+y[w[y[i]]];
        for(int u=1;u<=b;u++){
            for(int j=1;j<=k[i];j++){
                for(int o=1;o<=k[i];o++){
                    if(n[u][j]==n[u+1][o]){
                        cout<<z[u][j]+z[u+1][o]+v;
                        i++;
                    }
                }
            }
        }
    }
    return 0;
}
