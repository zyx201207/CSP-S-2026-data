#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tot,ans,a[200010];
bool b[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=30;j>=0;j--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(b[i]) continue;
            int ch=(a[i]>>j)&1;
            cnt+=ch;
        }
        if(cnt>=m){
            ans|=(1<<j);
            for(int i=1;i<=n;i++){
                int ch=(a[i]>>j)&1;
                if(!ch) b[i]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
