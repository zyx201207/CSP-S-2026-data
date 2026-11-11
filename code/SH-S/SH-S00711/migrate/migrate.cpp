#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,ans,pl;
int x[2000005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}