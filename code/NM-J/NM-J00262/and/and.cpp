#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    int n,m,ansl=LLONG_MIN,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<1<<n;i++){
        ans=0b111111111111111111111111111111;
        int oc=__builtin_popcount(i),x=i;
        if(oc==m){
            int pos=0;
            while(x>>pos){
                if(x&1){
                    ans&=a[n-pos];
                    ansl=max(ans,ansl);
                }
                pos++;
            }

        }

    }
    cout<<ansl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
