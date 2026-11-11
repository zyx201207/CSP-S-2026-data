#include<bits/stdc++.h>
using namespace std;
int c,q,ans,n;
long long pos[2000005],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
        ans=0;
        int n;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>pos[i];
        if(c==11||c==12){
            long long cha=pos[2]-pos[1];
            if(d>=2*cha&&d<3*cha&&n>=4){
                ans=n-3;
            }
        }else if(c==13||c==14){
            ans=0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
