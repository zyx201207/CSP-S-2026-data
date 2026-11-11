#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t,sum=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        int a[200005]{},g[200005]{},ans[200005]{};
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n&&(a[k]-a[j])<=d;k++){
                if(g[k]==0){
                    g[k]=g[j]+1;
                    ans[k]=1;
                }else if(g[k]==g[j]+1){
                    ans[k]+=ans[j];
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(ans[j]==2){
                sum++;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
