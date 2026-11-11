#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int k;
int w[600000],t[600000][600];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    if(c==0){
        cin>>n>>m>>d>>q;
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){

            cin>>k;
            int x;
            for(int j=1;j<=k;j++){
                cin>>x>>t[x][i];
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            ans=w[x]+w[y]+t[x][2]+t[y][1];
            for(int i=x+1;i<y;i++){
                for(int j=1;j<=k;j++){
                    ans+=t[i][j];
                }
            }
            cout<<ans;
        }
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
