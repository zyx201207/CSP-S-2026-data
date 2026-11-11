#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis1=1;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    int ci=0;
    int tt=t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int dc;
        ci++;
        vector<int>dao(n+1);
        for(int i=1;i<=n;i++){
            cin>>dao[i];
            if(i==2){
            dc=dao[i]-dao[i-1];
        }
        if(i>2&&vis1){
            if((dao[i]-dao[i-1])!=dc){
                vis1=0;
                }
            }
        }
        if(vis1){
            int h;
            if(n%2==0) h=n/2-1;
            if(n%2==1) h=n/2;
            int ju=0;
            int ans=0;
            for(int i=h;i>=1;i--){
                ju+=dc;
                if(ju<=d) ans++;
            }
            cout<<ans<<'\n';
            if(ci==tt) return 0;
        }
        else {
            int wan;
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dao[i]-dao[j]>d) break;
                    wan=i;
                }
            }
            vector<int>cun(n+1);
            for(int i=1;i<=n;i++){
                if(i==wan) continue;
                if(dao[wan]>=dao[i]) cun[i]=dao[wan]-dao[i];
                else{
                    cun[i]=dao[i]-dao[wan];
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==wan||j==wan) continue;
                    if(i==j) continue;
                    if(cun[i]==cun[j]) ans++;
                }
            }
            ans=ans/2;
            cout<<ans<<'\n';
            if(ci==tt) return 0;
        }
    }
    return 0;
}
