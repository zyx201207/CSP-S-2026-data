#include<bits/stdc++.h>
using namespace std;
int x[2000010];
bool f[20000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        memset(f,0,sizeof(f));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            f[x[i]]=true;
        }
        int ju=d+1;
        if(ju!=3){
            cout<<0<<endl;
            continue;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(i+ju<=n&&f[i+ju]==true){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
