#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
ll c,t,n,d,cnt,ans,sy,zg,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        cin>>x[1]>>x[2];
        for(int i=3;i<=n;i++){
            cin>>x[i];
            sy=d;
            cnt=0;
            for(int j=2;j<=i;j++){
                if(sy>=x[j]-x[j-1]){
                    sy-=x[j]-x[j-1];
                    cnt++;
                }
                else{
                    zg++;
                    sy=d;
                }
            }
            if(zg==1&&((i-1)%(d-1)+(i-1)/(d-1)>cnt||(i-1)%d==0))ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
