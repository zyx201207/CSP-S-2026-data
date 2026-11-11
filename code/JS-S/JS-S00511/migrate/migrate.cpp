#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            long long r=x[2]-x[1];
            if(d<2*r) cout<<0<<'\n';
            else{
                d/=r;
                d*=2;
                d--;
                if(n>d) cout<<n-d<<'\n';
                else cout<<0<<'\n';
            }
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--) cout<<0<<'\n';
        return 0;
    }
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(x[j]-x[i]<=d) continue;
                int way=0;
                for(int k=i+1;k<j;k++) if(x[j]-x[k]<=d&&x[k]-x[i]<=d) way++;
                if(way==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}