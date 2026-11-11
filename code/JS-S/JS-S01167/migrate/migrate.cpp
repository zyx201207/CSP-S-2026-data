#include <bits/stdc++.h>
using namespace std;
int c,t;
int il[10005];
int pre[10005];
void solve(){
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>il[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+3;j<=n;j++){
            bool flag=false;
            for(int k=i;k<=j-1;k++){
                if(il[k+1]-il[k]>d){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int q=1;q<=t;q++){
        solve();
    }
    return 0;
}
