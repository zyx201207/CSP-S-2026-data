#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN=200010;
int c,n,t,d,a[maxN],ans,f;
bool b(int x,int y){
    return (a[y]-a[x]<d+(a[2]-a[1])*2&&a[y]-a[x]>=d+(a[2]-a[1]));
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(;t>=1;t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
                if(b(i,1)){
                    f=i-1;break;
                }
            }
        }
        cout<<n-f<<endl;
    }
    return 0;
}