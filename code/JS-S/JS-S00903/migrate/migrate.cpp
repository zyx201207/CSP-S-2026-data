#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t,ans,n;
map<ll,ll>q[N];
void Floyed(){
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(q[i][j]!=n+1&&i!=k&&j!=k&&q[i][j]==q[i][k]+q[k][j])ans++;
                q[i][j]=min(q[i][k]+q[k][j],q[i][j]);
                q[j][i]=min(q[i][k]+q[k][j],q[j][i]);
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll d;
        cin>>n>>d;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            for(ll j=1;j<i;j++){
                if(a[i]-a[j]<=d)q[i][j]=1,q[j][i]=1;
                else{
                    q[i][j]=n+1;
                    q[j][i]=n+1;
                }
            }
        }
        ans=0;
        Floyed();
        cout<<ans<<endl;
    }
    return 0;
}
