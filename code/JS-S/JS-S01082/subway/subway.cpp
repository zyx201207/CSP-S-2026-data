#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50050],k,a[50050][50050],t[50050][50050],x,y,ans=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int j=1;j<=n;j++){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[j][i]>>t[j][i];
        }
    }
    while(q--){
        cin>>x>>y;
        ans+=w[x]+w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(a[i][j]==x){
                    ans+=t[i][j];
                }
                if(a[i][j]==y){
                    ans+=t[i][j];
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
