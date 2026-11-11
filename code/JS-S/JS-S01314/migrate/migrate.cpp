#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll c,t,n,d,x[N],ans;
bool flag[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            flag[i]=0;
            cin>>x[i];
        }
        ll sp=0;
        for(ll i=1;i<=n;i++){
            if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
                sp=i;
            }
        }
        for(ll i=1;i<=n-3;i++){
            if(x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[4]-x[1]>d){
                flag[i]=1;
            }
        }
        if(sp){
            if(!flag[sp-2]){
                ans++;
            }
            if(!flag[sp-1]){
                ans++;
            }
            cout<<ans<<endl;
            continue;
        }
        bool vis;
        for(ll i=1;i<n;i++){
            vis=0;
            for(ll j=i+3;j<=n;j++){
                if((vis&&flag[j-3])||(x[j]-x[j-1]>d)){
                    break;
                }
                if((!vis&&flag[j-3])||(vis&&!flag[j-3])){
                    ans++;
                    vis=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//zczxnbnbnb
