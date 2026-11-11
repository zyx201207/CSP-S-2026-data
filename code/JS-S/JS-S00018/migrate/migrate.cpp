#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n;
ll d,x[2000006],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(d>=2*(x[2]-x[1])){
            for(int i=d-1;i>=1;i-=2){
                if(d+i<=n){
                    ans+=n-(d+i);
                }

            }
        }
        else{
            ans=0;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
/*freopen
quanju/jubu
return 0
()[]{}
endl->\n
int->ll
*/
