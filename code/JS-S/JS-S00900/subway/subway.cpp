#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m+5];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c>=7 && c<=11){
        int f[m+5][m+5];
        memset(f,0x3f3f3f3f3f3f3f3f,sizeof(f));
        for(int i=1;i<=m;i++){
            f[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(k>1){
                int a,b,t1,t2;
                cin>>a>>t1>>b>>t2;
                f[a][b]=t1+t2;
                f[b][a]=t1+t2;
            }else{
                cin>>k;
            }
        }
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        while(q--){
            int st,ed;
            cin>>st>>ed;
            cout<<f[st][ed]+w[st]+w[ed]<<endl;
        }
    }

    return 0;
}
