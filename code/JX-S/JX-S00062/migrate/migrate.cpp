#include<bits/stdc++.h>
using namespace std;
int n,x[2000005],c,t,d,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int cha=x[2]-x[1];
        int step=d/cha+1;
        int minn=step+1;
        int maxx=step*2-1;
        for(int i=1;i+maxx-2<=n;i++){
            ans++;
        }
        cout<<ans<<endl;
    }
}