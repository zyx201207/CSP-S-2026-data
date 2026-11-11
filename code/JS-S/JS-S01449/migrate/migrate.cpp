#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int mi,t;
    cin>>mi>>t;
    if(mi==11||mi==12){
        for(int ii=1;ii<=t;ii++){
            int n,d,x[2000010];
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>x[i];
            int dc=x[2]-x[1];
            int ma=(d-d%dc)/dc+1;
            cout<<n-ma;
        }
        return 0;
    }
    for(int ii=1;ii<=t;ii++){
        int n;
        double d,x[5010],bei;
        cin>>n>>d;
        bei=d/2;
        d=2;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            x[i]/=bei;
        }
        for(int i=1;i<=n-3;i++){
            if(x[i+3]-x[i]>2&&x[i+3]-x[i+2]<=2&&x[i+3]-x[i+1]<=2&&x[i+2]-x[i]<=22&&x[i+1]-x[i]<=2){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
